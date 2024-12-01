// CShopResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CShopResultDlg.h"
#include "Player.h"
#include "CMainDlg.h"

bool camera = 0;
bool computer = 0;
bool editor = 0;

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
	//  DDX_Text(pDX, IDC_CURRENT_HEALTH, m_strCurrentHealth);
	DDX_Control(pDX, IDC_CURRENT_HEALTH, m_tCurrentHealth);
	//  DDX_Control(pDX, IDC_CURRENT_MONEY, m_tCurrentMoney);
	DDX_Control(pDX, IDC_PREVIOUS_HEALTH, m_tPreviousHealth);
	DDX_Control(pDX, IDC_PREVIOUS_MONEY, m_tPreviousMoney);
	DDX_Control(pDX, IDC_CURRENT_MONEY, m_tCurrentMoney);
	//  DDX_Control(pDX, IDC_BOUGHT, m_tBought);
	DDX_Control(pDX, IDC_BOUGHT, m_tBought);
}


BEGIN_MESSAGE_MAP(CShopResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEXTDAY_BUTTON, &CShopResultDlg::OnBnClickedNextdayButton)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
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


BOOL CShopResultDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CString previousMoney;
	CString previousHealth;
	CString currentMoney;
	CString currentHealth;
	CString bought;

	previousMoney.Format(_T("%d"), Player::instance.GetPreviousMoney());
	previousHealth.Format(_T("%d"), Player::instance.GetPreviousHealth());
	currentMoney.Format(_T("%d"), Player::instance.GetMoney());
	currentHealth.Format(_T("%d"), Player::instance.GetHealth());
	
	if (Player::instance.GetShopItem(HEALTH))
		bought.Format(_T("헬스를 했더니 체력이 올랐어!"));

	else if (Player::instance.GetShopItem(CAMERA) && camera == 0) {
		bought.Format(_T("카메라를 구입했어!"));
		camera++;
	}
	else if (Player::instance.GetShopItem(COMPUTER) && computer == 0) {
		bought.Format(_T("컴퓨터를 구입했어!"));
		computer++;
	}
	else if (Player::instance.GetShopItem(EDITOR) && editor == 0) {
		bought.Format(_T("편집자를 고용했어!"));
		editor++;
	}


	m_tPreviousMoney.SetWindowTextW(previousMoney);
	m_tPreviousHealth.SetWindowTextW(previousHealth);
	m_tCurrentMoney.SetWindowTextW(currentMoney);
	m_tCurrentHealth.SetWindowTextW(currentHealth);
	m_tBought.SetWindowTextW(bought);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CShopResultDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);

}


HBRUSH CShopResultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
