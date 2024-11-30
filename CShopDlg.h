#pragma once
#include "afxdialogex.h"


// CShopDlg 대화 상자

class CShopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShopDlg)

public:
	CShopDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CShopDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void showShopResultDlg();
	afx_msg void OnBnClickedShopHealth();
	afx_msg void OnBnClickedShopCamera();
};
