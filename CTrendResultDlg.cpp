// CTrendResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CTrendResultDlg.h"
#include "CMainDlg.h"
#include "CEndingDlg.h"
#include "Player.h"


// CTrendResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CTrendResultDlg, CDialogEx)

CTrendResultDlg::CTrendResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRENDRESULT_DIALOG, pParent)
{

}

CTrendResultDlg::~CTrendResultDlg()
{
}

void CTrendResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TRENDRESULT, m_tTrendResult);
}


BEGIN_MESSAGE_MAP(CTrendResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEXTDAY_BUTTON, &CTrendResultDlg::OnClickedNextdayButton)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CTrendResultDlg 메시지 처리기


void CTrendResultDlg::OnClickedNextdayButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	goNextDay();
	
}


void CTrendResultDlg::goNextDay()
{
	// TODO: 여기에 구현 코드 추가.

	Player::instance.AddDay();

	if (Player::instance.GetDay() >= 50 && Player::instance.GetFollower() < 1'000'000) {
		showEnding(BADENDING_1);
	}
	else if (Player::instance.GetDay() >= 50 && Player::instance.GetFollower() >= 1'000'000) {
		showEnding(HAPPYENDING);
	}
	else if (Player::instance.GetHealth() <= 0) {
		showEnding(BADENDING_2);
	}
	else {
		showMainDlg();
	}
}

void CTrendResultDlg::showMainDlg() {

	CMainDlg* pMainDlg = new CMainDlg();
	pMainDlg->Create(IDD_MAIN_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pMainDlg->GetWindowRect(&currentRect);
	pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}


BOOL CTrendResultDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}



HBRUSH CTrendResultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CTrendResultDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	switch (Player::instance.GetTrend())
	{
	case GAME:
		m_tTrendResult.SetWindowTextW(_T("트렌드를 조사해본 결과, 내일은 재미있는 방송을 사람들이 좋아할 것 같아!"));
		break;

	case TALK:
		m_tTrendResult.SetWindowTextW(_T("트렌드를 조사해본 결과, 내일은 조용히 힐링하는 느낌의 방송이 좋겠어!"));
		break;

	case MUKBANG:
		m_tTrendResult.SetWindowTextW(_T("트렌드를 조사해본 결과, 최근에 출시된 맛있는 음식이 떠오르는거 같아!"));
		break;

	case BEAUTY:
		m_tTrendResult.SetWindowTextW(_T("트렌드를 조사해본 결과, 요즘 나의 화장법에 궁금해하는 사람이 많아진거같아!"));
		break;

	case EXERCISE:
		m_tTrendResult.SetWindowTextW(_T("트렌드를 조사해본 결과, 내일은 활동적으로 움직이는 방송이 필요할거같아!"));
		break;

	default:
		break;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTrendResultDlg::showEnding(int endingId)
{
	// TODO: 여기에 구현 코드 추가.
	CEndingDlg* pEndingDlg = new CEndingDlg();

	pEndingDlg->m_EndingType = endingId;

	pEndingDlg->Create(IDD_ENDING_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pEndingDlg->GetWindowRect(&currentRect);
	pEndingDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}
