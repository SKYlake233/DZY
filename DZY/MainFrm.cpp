
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "DZY.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_NOTIFYICON WM_USER+100

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_EXIT, &CMainFrame::OnExit)
	ON_MESSAGE(WM_NOTIFYICON, &CMainFrame::NotifyIcon)
	ON_COMMAND(ID_HIDE, &CMainFrame::OnShow)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构
 
CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}
	if (!m_wndToolBarNew.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBarNew.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBarNew.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndToolBarNew);

	nTay.cbSize = sizeof(NOTIFYICONDATA);
	nTay.uID = IDI_ICON1;
	nTay.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	nTay.hWnd = this->m_hWnd;
	wcscpy_s(nTay.szTip, L"提示!");
	nTay.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nTay.uCallbackMessage = WM_NOTIFYICON;
	Shell_NotifyIconW(NIM_ADD, &nTay);

	return 0;
}

LRESULT CMainFrame::NotifyIcon(WPARAM wParam, LPARAM lParam)
{
	CMenu menu;
	switch (lParam)
	{
	case WM_RBUTTONDOWN:
		menu.LoadMenuW(IDR_MENU2);
		CMenu* pop = menu.GetSubMenu(0);
		if (IsWindowVisible()) {
			pop->ModifyMenuW(ID_HIDE, MF_STRING, ID_HIDE, L"隐藏(&H)");
		}
		else {
			pop->ModifyMenuW(ID_HIDE, MF_STRING, ID_HIDE, L"显示(&S)");
		}
		CPoint point;
		GetCursorPos(&point);
		SetForegroundWindow();
		pop->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y,this);
		break;
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	if (IsWindowVisible()) {
		ShowWindow(SW_HIDE);
	}
	else {
		ShowWindow(SW_NORMAL);
	}
}


void CMainFrame::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	Shell_NotifyIconW(NIM_DELETE, &nTay);
	CFrameWnd::OnClose();
}

void CMainFrame::OnClose()
{
	// TODO: 在此添加命令处理程序代码
	Shell_NotifyIconW(NIM_DELETE, &nTay);
	OnClose();
}
