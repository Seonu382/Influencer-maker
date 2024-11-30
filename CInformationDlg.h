#pragma once
#include "afxdialogex.h"


// CInformationDlg 대화 상자

class CInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInformationDlg)

public:
	CInformationDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInformationDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFORMATION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedConfirmButton();
	CString m_strName;
};
