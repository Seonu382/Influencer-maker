#pragma once
#include "afxdialogex.h"
#include "CLiveDlg.h"
#include "RandomEvent.h"


// CRandomResultDlg 대화 상자

class CRandomResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRandomResultDlg)

public:
	CRandomResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRandomResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANDOMRESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_bAfterLive;
	void showLiveResult();
	CLiveDlg* m_pLiveDlg;
	void setParentDlg(CLiveDlg* pParent);
	afx_msg void OnClickedNextButton();
	RandomEvent m_currentRandomEvent;
	virtual BOOL OnInitDialog();
	CStatic m_tRandomResult;
	bool m_bChoice;
	CStatic m_tFollower;
	CStatic m_tMoney;
	CStatic m_tHealth;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
