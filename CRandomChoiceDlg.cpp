// CRandomChoiceDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CRandomChoiceDlg.h"
#include "CLiveDlg.h"
#include "CRandomResultDlg.h"
#include "CLiveResultDlg.h"


// CRandomChoiceDlg 대화 상자

IMPLEMENT_DYNAMIC(CRandomChoiceDlg, CDialogEx)

CRandomChoiceDlg::CRandomChoiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANDOMCHOICE_DIALOG, pParent)
{

}

CRandomChoiceDlg::~CRandomChoiceDlg()
{
}

void CRandomChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RANDOMEVENT, m_tRandomEvent);
	DDX_Control(pDX, IDC_YES_BUTTON, m_btnYesButton);
	DDX_Control(pDX, IDC_NO_BUTTON, m_btnNoButton);
}


BEGIN_MESSAGE_MAP(CRandomChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_YES_BUTTON, &CRandomChoiceDlg::OnClickedYesButton)
	ON_BN_CLICKED(IDC_NO_BUTTON, &CRandomChoiceDlg::OnClickedNoButton)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRandomChoiceDlg 메시지 처리기


void CRandomChoiceDlg::OnClickedYesButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	switch (m_liveRandomEvent.GetEventType())
	{
	case GWANGGO:
		Player::instance.SetMainEvent(GWANGGO, ACCEPT);
		break;
	case HABBANG:
		Player::instance.SetMainEvent(HABBANG, ACCEPT);
		break;
	case SACHE:
		Player::instance.SetMainEvent(SACHE, ACCEPT);
		break;
	default:
		break;
	}
	showRandomResultDlg(true);
}


void CRandomChoiceDlg::OnClickedNoButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	switch (m_liveRandomEvent.GetEventType())
	{
	case GWANGGO:
		Player::instance.SetMainEvent(GWANGGO, DENY);
		break;
	case HABBANG:
		Player::instance.SetMainEvent(HABBANG, DENY);
		break;
	case SACHE:
		Player::instance.SetMainEvent(SACHE, ACCEPT);
		break;
	default:
		break;
	}
	showRandomResultDlg(false);
}

void CRandomChoiceDlg::showRandomResultDlg(bool _Choice)
{
	// TODO: 여기에 구현 코드 추가.
	CRandomResultDlg* pRandomResultDlg = new CRandomResultDlg();
	pRandomResultDlg->m_currentRandomEvent = m_liveRandomEvent;
	pRandomResultDlg->m_bChoice = _Choice;
	pRandomResultDlg->Create(IDD_RANDOMRESULT_DIALOG);
	pRandomResultDlg->m_bAfterLive = m_bAfterLive;
	pRandomResultDlg->setParentDlg(m_pLiveDlg);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pRandomResultDlg->GetWindowRect(&currentRect);
	pRandomResultDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}



void CRandomChoiceDlg::setParentDialog(CLiveDlg* pParent)
{
	// TODO: 여기에 구현 코드 추가.
	m_pLiveDlg = pParent;
}


BOOL CRandomChoiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	if (!m_bAfterLive) {
		m_liveRandomEvent = RandomEvent::GetLiveRandomEvent();
	}
	else {
		m_liveRandomEvent = RandomEvent::GetAfterRandomEvent();
	}
	
	m_btnYesButton.SetWindowTextW(CA2T(m_liveRandomEvent.GetYesButton().c_str()));
	m_btnNoButton.SetWindowTextW(CA2T(m_liveRandomEvent.GetNoButton().c_str()));
	m_tRandomEvent.SetWindowTextW(CA2T(m_liveRandomEvent.GetEventDescription().c_str()));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



BOOL CRandomChoiceDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH CRandomChoiceDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
