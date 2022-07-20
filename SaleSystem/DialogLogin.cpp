// DialogLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DialogLogin.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CDialogLogin 对话框

IMPLEMENT_DYNAMIC(CDialogLogin, CDialogEx)

CDialogLogin::CDialogLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
{

}

CDialogLogin::~CDialogLogin()
{
	m_key.Close();
}

void CDialogLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USER_TEXT, m_userEdit);
	DDX_Control(pDX, IDC_PWD_TEXT, m_pwdEdit);
	DDX_Control(pDX, IDC_CHECK_IS_AUTO_SIGN, c_check_isAutoSign);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogLogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogLogin::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDialogLogin 消息处理程序


void CDialogLogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString uerEdit,pwdEdit;
	GetDlgItemTextW(IDC_USER_TEXT, uerEdit);
	GetDlgItemTextW(IDC_PWD_TEXT, pwdEdit);
	if(uerEdit==m_name)
	{
		if(pwdEdit==m_pwd)
		{
			//AfxMessageBox(L"验证成功");
			if(c_check_isAutoSign.GetCheck())
			{
				m_isAutoSign = 1;
			}else
			{
				m_isAutoSign = 0;
			}

			//我的
			m_key.SetDWORDValue(_T("auto_sign"), m_isAutoSign);
			CDialogEx::OnOK();
		}
		else
		{
			AfxMessageBox(L"密码错误");
			//AfxMessageBox(m_pwd);
		}
	}
	else
	{
		AfxMessageBox(L"用户名错误");
	}
}


BOOL CDialogLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	bool isTrue=TRUE;
	//AfxMessageBox(isTrue=TRUE?1:0);
	bool is_isTrue = isTrue;


	m_infoFile.ReadLogin(m_name, m_pwd);
	//读取注册表中是否记住密码
	m_key.Create(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\SaleSystem\\login"));
	m_key.Close();
	BOOL bOpenReg = m_key.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\SaleSystem\\login"));
	//AfxMessageBox(bOpenReg==true?L"TRUE":L"FALSE");
	if(true)
	{
		DWORD isAutoSign;
		m_key.QueryDWORDValue(_T("auto_sign"), isAutoSign);
		m_isAutoSign= isAutoSign;
	}
	
	c_check_isAutoSign.SetCheck(m_isAutoSign);
	CString tmp;
	//
	//tmp.Format(L"%d", m_isAutoSign);
	//AfxMessageBox(tmp);
	if(m_isAutoSign!=0)
	{
		SetDlgItemTextW(IDC_USER_TEXT, m_name);
		SetDlgItemTextW(IDC_PWD_TEXT, m_pwd);
		// m_userEdit.SetWindowTextW(m_name);
		// m_userEdit.SetWindowTextW(m_pwd);

		((CEdit*)GetDlgItem(IDC_USER_TEXT))->GetWindowText(m_name);
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogLogin::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CDialogLogin::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CDialogEx::OnClose();
	exit(0);
}


BOOL CDialogLogin::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			return TRUE;
		case VK_ESCAPE:
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
