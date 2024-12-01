// CShopDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CMainDlg.h"
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
	ON_BN_CLICKED(IDC_SHOP_BACK, &CShopDlg::OnBnClickedShopBack)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
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


BOOL CShopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	if (Player::instance.GetShopItem(CAMERA))
		GetDlgItem(IDC_SHOP_CAMERA)->EnableWindow(false);
	if (Player::instance.GetShopItem(COMPUTER))
		GetDlgItem(IDC_SHOP_COMPUTER)->EnableWindow(false);
	if (Player::instance.GetShopItem(EDITOR))
		GetDlgItem(IDC_SHOP_EDITOR)->EnableWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CShopDlg::OnBnClickedShopHealth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"헬스를 하시겠습니까?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리

		
		if (Player::instance.GetMoney() < 00) {
			MessageBox(L"돈이 부족합니다.", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			Player::instance.AddHealth(10);
			Player::instance.AddMoney(-500);
			Player::instance.SetShopItem(HEALTH, TRUE);
			showShopResultDlg();
			Player::instance.SetShopItem(HEALTH, FALSE);
		}
	}
}


void CShopDlg::OnBnClickedShopCamera()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"카메라를 구매하시겠습니까?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 000) {
			MessageBox(L"돈이 부족합니다.", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			plusSkillDlg(10);
			Player::instance.AddMoney(-2000);
			Player::instance.SetShopItem(CAMERA, TRUE);
			showShopResultDlg();
		}
	}
}

void CShopDlg::OnBnClickedShopComputer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"컴퓨터를 구매하시겠습니까?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 000) {
			MessageBox(L"돈이 부족합니다.", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			plusSkillDlg(20);
			Player::instance.AddMoney(-5000);
			Player::instance.SetShopItem(COMPUTER, TRUE);
			showShopResultDlg();
		}
	}
}


void CShopDlg::OnBnClickedShopEditor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int result = MessageBox(L"편집자를 고용하시겠습니까?", L"", MB_OKCANCEL | MB_ICONWARNING);

	if (result == IDOK)
	{
		// 사용자가 "확인"을 클릭했을 때 처리
		if (Player::instance.GetMoney() < 0000) {
			MessageBox(L"돈이 부족합니다.", L"", MB_OK | MB_ICONWARNING);
		}
		else {
			plusSkillDlg(30);
			Player::instance.AddMoney(-20000);
			Player::instance.SetShopItem(EDITOR, TRUE);
			showShopResultDlg();
		}
	}

}

void CShopDlg::OnBnClickedShopBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainDlg* pMainDlg = new CMainDlg();
	pMainDlg->Create(IDD_MAIN_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pMainDlg->GetWindowRect(&currentRect);
	pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}



BOOL CShopDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;


	return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH CShopDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(253, 253, 253));
		hbr = ::CreateSolidBrush(RGB(253, 253, 253));
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;

}
