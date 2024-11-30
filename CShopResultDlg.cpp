// CShopResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CShopResultDlg.h"
#include "Player.h"
#include "CMainDlg.h"

// CShopResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CShopResultDlg, CDialogEx)

CShopResultDlg::CShopResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOPRESULT_DIALOG, pParent)
{

}

CShopResultDlg::~CShopResultDlg()
{
}

void CShopResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShopResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEXTDAY_BUTTON, &CShopResultDlg::OnBnClickedNextdayButton)
END_MESSAGE_MAP()


// CShopResultDlg 메시지 처리기

void CShopResultDlg::showMainDlg()
{
	// TODO: 여기에 구현 코드 추가.

	CMainDlg* pMainDlg = new CMainDlg();

	pMainDlg->Create(IDD_MAIN_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pMainDlg->GetWindowRect(&currentRect);
	pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();


}

void CShopResultDlg::goNextDay()
{
	// TODO: 여기에 구현 코드 추가.

	Player::instance.AddDay();

	showMainDlg();
}



void CShopResultDlg::OnBnClickedNextdayButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	goNextDay();

}
