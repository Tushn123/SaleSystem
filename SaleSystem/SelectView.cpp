// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SelectView.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	HICON icon =AfxGetApp()->LoadIconW(IDI_ICON_PEN);
	m_imagelist.Create(30, 30, ILC_COLOR32, 1, 1);
	m_imagelist.Add(icon);
	m_treeCtrl = &GetTreeCtrl();
	m_treeCtrl->SetImageList(&m_imagelist, TVSIL_NORMAL);

	m_treeCtrl->InsertItem(TEXT("个人信息"),0, 0, nullptr);
	m_treeCtrl->InsertItem(TEXT("销售管理"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("库存信息"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("库存添加"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("库存删除"), 0, 0, NULL);
	
}

void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	HTREEITEM item = m_treeCtrl->GetSelectedItem();
	CString itemText = m_treeCtrl->GetItemText(item);
	if(itemText=="个人信息")
	{
		
	}
	else if(itemText=="销售管理")
	{

	}
	else if (itemText == "库存信息")
	{

	}
	else if (itemText == "库存增加")
	{

	}
	else if (itemText == "库存删除")
	{

	}
}
