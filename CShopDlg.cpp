// CShopDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CShopDlg.h"
#include "CShopResultDlg.h"
#include "Player.h"

// CShopDlg 대화 상자

IMPLEMENT_DYNAMIC(CShopDlg, CDialogEx)

CShopDlg::CShopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOP_DIALOG, pParent)
{

}

CShopDlg::~CShopDlg()
{
}

void CShopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShopDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SHOP_HEALTH, &CShopDlg::OnBnClickedShopHealth)
	ON_BN_CLICKED(IDC_SHOP_CAMERA, &CShopDlg::OnBnClickedShopCamera)
	ON_BN_CLICKED(IDC_SHOP_COMPUTER, &CShopDlg::OnBnClickedShopComputer)
	ON_BN_CLICKED(IDC_SHOP_EDITOR, &CShopDlg::OnBnClickedShopEditor)
END_MESSAGE_MAP()


// CShopDlg 메시지 처리기

void CShopDlg::showShopResultDlg()
{
		CShopResultDlg* pShopResultDlg = new CShopResultDlg();
		pShopResultDlg->Create(IDD_SHOPRESULT_DIALOG);

		CRect parentRect, currentRect;
		GetWindowRect(&parentRect);
		pShopResultDlg->GetWindowRect(&currentRect);
		pShopResultDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

		DestroyWindow();
}

void CShopDlg::plusSkillDlg(int plus) 
{
	Player::instance.SetSkilledGame(Player::instance.GetSkilledGame() + plus);
	Player::instance.SetSkilledTalk(Player::instance.GetSkilledTalk() + plus);
	Player::instance.SetSkilledMukbang(Player::instance.GetSkilledMukbang() + plus);
	Player::instance.SetSkilledBeauty(Player::instance.GetSkilledBeauty() + plus);
	Player::instance.SetSkilledExercise(Player::instance.GetSkilledExercise() + plus);
}

void CShopDlg::OnBnClickedShopHealth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	int result = MessageBox(L"진짜 헬스?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 10000) {
			MessageBox(L"너 돈이 없어", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			Player::instance.AddHealth(10);
			showShopResultDlg();
		}
	}
}


void CShopDlg::OnBnClickedShopCamera()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"진짜 카메라?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 10000) {
			MessageBox(L"너 돈이 없어", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			plusSkillDlg(10);
			showShopResultDlg();
		}
	}
}


void CShopDlg::OnBnClickedShopComputer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"진짜 컴퓨터?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 10000) {
			MessageBox(L"너 돈이 없어", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			plusSkillDlg(20);
			showShopResultDlg();
		}
	}
}


void CShopDlg::OnBnClickedShopEditor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"진짜 편집자?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 10000) {
			MessageBox(L"너 돈이 없어", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			plusSkillDlg(30);
			showShopResultDlg();
		}
	}
}
