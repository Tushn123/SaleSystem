#pragma once
#include "afxwin.h"
#include "InfoFile.h"


// CDialogLogin 对话框

class CDialogLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogLogin)

public:
	CDialogLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogLogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CEdit m_userEdit;
	CEdit m_pwdEdit;
	CString m_name, m_pwd;
	int m_isAutoSign;
	CInfoFile m_infoFile;
	CRegKey m_key;
	

public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
private:
	CButton c_check_isAutoSign;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
