// CRandomResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CRandomResultDlg.h"
#include "CLiveDlg.h"
#include "CLiveResultDlg.h"


// CRandomResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CRandomResultDlg, CDialogEx)

CRandomResultDlg::CRandomResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANDOMRESULT_DIALOG, pParent)
{

}

CRandomResultDlg::~CRandomResultDlg()
{
}

void CRandomResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RANDOMRESULT, m_tRandomResult);
	DDX_Control(pDX, IDC_FOLLOWER, m_tFollower);
	DDX_Control(pDX, IDC_MONEY, m_tMoney);
	DDX_Control(pDX, IDC_HEALTH, m_tHealth);
}


BEGIN_MESSAGE_MAP(CRandomResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEXT_BUTTON, &CRandomResultDlg::OnClickedNextButton)
END_MESSAGE_MAP()


// CRandomResultDlg 메시지 처리기


void CRandomResultDlg::showLiveResult()
{
	// TODO: 여기에 구현 코드 추가.
	CLiveResultDlg* pLiveResultDlg = new CLiveResultDlg();
	pLiveResultDlg->Create(IDD_LIVERESULT_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pLiveResultDlg->GetWindowRect(&currentRect);
	pLiveResultDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}


void CRandomResultDlg::setParentDlg(CLiveDlg* pParent)
{
	// TODO: 여기에 구현 코드 추가.
	m_pLiveDlg = pParent;
}


void CRandomResultDlg::OnClickedNextButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_bAfterLive) {
		if (m_pLiveDlg) {
			m_pLiveDlg->SetTimer(1, 3000, NULL);
			DestroyWindow();
		}
	}
	else {
		showLiveResult();
	}
}


BOOL CRandomResultDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_tRandomResult.SetWindowTextW(CA2T((m_bChoice) ? m_currentRandomEvent.GetYesDescription().c_str() : m_currentRandomEvent.GetNoDescription().c_str()));

	CString follower;
	CString money;
	CString health;

	follower.Format(_T("팔로워 변화 : %d"), (m_bChoice) ? m_currentRandomEvent.GetYesFollower() : m_currentRandomEvent.GetNoFollower());
	money.Format(_T("돈 변화 : %d"), (m_bChoice) ? m_currentRandomEvent.GetYesMoney() : m_currentRandomEvent.GetNoMoney());
	health.Format(_T("체력 변화 : %d"), (m_bChoice) ? m_currentRandomEvent.GetYesHealth() : m_currentRandomEvent.GetNoHealth());

	m_tFollower.SetWindowTextW(follower);
	m_tMoney.SetWindowTextW(money);
	m_tHealth.SetWindowTextW(health);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
