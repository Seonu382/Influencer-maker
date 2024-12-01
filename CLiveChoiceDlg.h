#pragma once
#include "afxdialogex.h"


// CLiveChoiceDlg 대화 상자

class CLiveChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLiveChoiceDlg)

public:
	CLiveChoiceDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLiveChoiceDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIVECHOICE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void showLiveDlg();
	afx_msg void OnClickedGameButton();
	afx_msg void OnClickedTalkButton();
	afx_msg void OnClickedMukbangButton();
	afx_msg void OnClickedBeautyButton();
	afx_msg void OnClickedExerciseButton();
	afx_msg void OnBnClickedLiveBack();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
