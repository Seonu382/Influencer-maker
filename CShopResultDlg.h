#pragma once
#include "afxdialogex.h"


// CShopResultDlg 대화 상자

class CShopResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShopResultDlg)

public:
	CShopResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CShopResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOPRESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void showMainDlg();
	void goNextDay();
	afx_msg void OnBnClickedNextdayButton();
	virtual BOOL OnInitDialog();
//	CString m_strCurrentHealth;
	CStatic m_tCurrentHealth;
//	CStatic m_tCurrentMoney;
	CStatic m_tPreviousHealth;
	CStatic m_tPreviousMoney;
	CStatic m_tCurrentMoney;
//	CStatic m_tBought;
	void showEnding(int endingId);
};
