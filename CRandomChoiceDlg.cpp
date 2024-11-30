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
}


BEGIN_MESSAGE_MAP(CRandomChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_YES_BUTTON, &CRandomChoiceDlg::OnClickedYesButton)
	ON_BN_CLICKED(IDC_NO_BUTTON, &CRandomChoiceDlg::OnClickedNoButton)
END_MESSAGE_MAP()


// CRandomChoiceDlg 메시지 처리기


void CRandomChoiceDlg::OnClickedYesButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.AddFollower(m_liveRandomEvent.GetYesFollower());
	Player::instance.AddMoney(m_liveRandomEvent.GetYesMoney());
	Player::instance.AddHealth(m_liveRandomEvent.GetYesHealth());
	showRandomResultDlg(true);
}


void CRandomChoiceDlg::OnClickedNoButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.AddFollower(m_liveRandomEvent.GetNoFollower());
	Player::instance.AddMoney(m_liveRandomEvent.GetNoMoney());
	Player::instance.AddHealth(m_liveRandomEvent.GetNoHealth());
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

	ShowWindow(SW_HIDE);
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
	m_liveRandomEvent = RandomEvent::GetLiveRandomEvent();
	
	m_tRandomEvent.SetWindowTextW(CA2T(m_liveRandomEvent.GetEventDescription().c_str()));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
