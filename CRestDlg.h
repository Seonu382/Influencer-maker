#pragma once
#include "afxdialogex.h"


// CRestDlg 대화 상자

class CRestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRestDlg)

public:
	CRestDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRestDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void showMainDlg();
	void goNextDay();
	CStatic m_tCurrentHealth;
	CStatic m_tPreviousHealth;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedNextdayButton();
	void showEnding(int endingId);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
