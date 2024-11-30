#pragma once
#include "afxdialogex.h"
#include "Player.h"


// CMainDlg 대화 상자

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMainDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedLiveButton();
	afx_msg void OnClickedTrendButton();
	afx_msg void OnPaint();
	CStatic m_tDay;
	CStatic m_tFollower;
	CStatic m_tHealth;
	CStatic m_tMoney;
	virtual BOOL OnInitDialog();
};
