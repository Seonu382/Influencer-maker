// CResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CResultDlg.h"


// CResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CResultDlg, CDialogEx)

CResultDlg::CResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RESULT_DIALOG, pParent)
{

}

CResultDlg::~CResultDlg()
{
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CResultDlg, CDialogEx)
END_MESSAGE_MAP()


// CResultDlg 메시지 처리기
