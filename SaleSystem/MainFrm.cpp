
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "SaleSystem.h"

#include "MainFrm.h"
#include "SelectView.h"
#include "DispalyView.h"

#include <iostream>

#include "UserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	

}

CMainFrame::~CMainFrame()
{
	FreeConsole();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	::AllocConsole();//打开控件台资源
	FILE *fp;
	freopen_s(&fp, "CONOUT$", "w+t", stdout);


	//SetClassLong()
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));
	MoveWindow(0, 0, 800, 500);
	CenterWindow();
	SetTitle(L"2022/7/12");
	TRACE(L"111111111111111111");
	printf(",,,,,,");
	std::cout << "--------------";

	return 0;
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext   Context;
	switch (wParam)
	{
	case NM_A:
		{
			//CUserDlg类需要包含头文件#include "UserDlg.h"
			Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
			Context.m_pCurrentFrame = this;
			Context.m_pLastView = (CFormView *)m_splitter_wnd.GetPane(0, 1);
			m_splitter_wnd.DeleteView(0, 1);
			m_splitter_wnd.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600, 500), &Context);
			CUserDlg *pNewView = (CUserDlg *)m_splitter_wnd.GetPane(0, 1);
			m_splitter_wnd.RecalcLayout();
			pNewView->OnInitialUpdate();
			m_splitter_wnd.SetActivePane(0, 1);
		}
		break;
	case NM_B:
		MessageBox(_T("NM_B"));
		break;
	case NM_C:
		MessageBox(_T("NM_C"));
		break;
	case NM_D:
		MessageBox(_T("NM_D"));
		break;
	case NM_E:
		MessageBox(_T("NM_E"));
		break;
	default:
		MessageBox(_T("error"));
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



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	m_splitter_wnd.CreateStatic(this, 1, 2);
	m_splitter_wnd.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);
	m_splitter_wnd.CreateView(0, 1, RUNTIME_CLASS(CDispalyView), CSize(600, 500), pContext);

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	return TRUE;
}
