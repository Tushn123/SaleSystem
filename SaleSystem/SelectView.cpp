// SelectView.cpp : ʵ���ļ�
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


// CSelectView ���

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


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	HICON icon =AfxGetApp()->LoadIconW(IDI_ICON_PEN);
	m_imagelist.Create(30, 30, ILC_COLOR32, 1, 1);
	m_imagelist.Add(icon);
	m_treeCtrl = &GetTreeCtrl();
	m_treeCtrl->SetImageList(&m_imagelist, TVSIL_NORMAL);

	m_treeCtrl->InsertItem(TEXT("������Ϣ"),0, 0, nullptr);
	m_treeCtrl->InsertItem(TEXT("���۹���"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("�����Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);
	
}

void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	HTREEITEM item = m_treeCtrl->GetSelectedItem();
	CString itemText = m_treeCtrl->GetItemText(item);
	if(itemText=="������Ϣ")
	{
		
	}
	else if(itemText=="���۹���")
	{

	}
	else if (itemText == "�����Ϣ")
	{

	}
	else if (itemText == "�������")
	{

	}
	else if (itemText == "���ɾ��")
	{

	}
}
