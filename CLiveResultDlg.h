#pragma once
#include "afxdialogex.h"
#include "CMainDlg.h"


// CLiveResultDlg 대화 상자

class CLiveResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLiveResultDlg)

public:
	CLiveResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLiveResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIVERESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedNextdayButton();
	void showMainDlg();
	void goNextDay();
	CStatic m_tPreviousFollower;
	CStatic m_tPreviousMoney;
	CStatic m_tPreviousHealth;
	CStatic m_tCurrentFollower;
	CStatic m_tCurrentHealth;
	CStatic m_tCurrentMoney;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
