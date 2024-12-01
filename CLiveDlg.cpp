// CLiveDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CLiveDlg.h"
#include "CRandomChoiceDlg.h"
#include "Player.h"
#include "CLiveDlg.h"
#include "CLiveChat.h"
#include "CLiveResultDlg.h"
#include <iostream>



// CLiveDlg 대화 상자

IMPLEMENT_DYNAMIC(CLiveDlg, CDialogEx)

CLiveDlg::CLiveDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIVE_DIALOG, pParent)
{

}

CLiveDlg::~CLiveDlg()
{
}

void CLiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIVE_CHAT, m_cbLiveChat);
}


BEGIN_MESSAGE_MAP(CLiveDlg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CLiveDlg 메시지 처리기


BOOL CLiveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(0, 3000, NULL);
	SetTimer(3, 1000, NULL);

	CStatic* p_lamp_image = (CStatic*)GetDlgItem(IDC_LIVE);
	CBitmap lamp_image;
	HBITMAP h_old_bitmap = nullptr;

	int positiveCheck = 0;

	switch (Player::instance.GetCurrentTheme())
	{
	case GAME:
		lamp_image.LoadBitmap(IDB_LIVE_GAME);
		positiveCheck = Player::instance.GetGame();
		break;
	case TALK:
		lamp_image.LoadBitmap(IDB_LIVE_TALK);
		positiveCheck = Player::instance.GetTalk();
		break;
	case MUKBANG:
		lamp_image.LoadBitmap(IDB_LIVE_MUKBANG);
		positiveCheck = Player::instance.GetMukbang();
		break;
	case BEAUTY:
		lamp_image.LoadBitmap(IDB_LIVE_BEAUTY);
		positiveCheck = Player::instance.GetBeauty();
		break;

	case EXERCISE:
		lamp_image.LoadBitmap(IDB_LIVE_EXERCISE);
		positiveCheck = Player::instance.GetExercise();
		break;
	default:
		break;
	}

	h_old_bitmap = p_lamp_image->SetBitmap(lamp_image);
	if (h_old_bitmap != NULL) ::DeleteObject(h_old_bitmap);
	lamp_image.Detach();

	m_cbLiveChat.ResetContent();

	bool positive = false;
	if (positiveCheck > 100)
		positive = true;

	m_currentChatIndex = 0;
	m_selectedChats = CLiveChat::GetRandomChats(positive, 6);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CLiveDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	srand(static_cast<unsigned int>(time(NULL)));


	if (nIDEvent == 0) {
		if (rand() % 2 == 1)
			showRandomChoice(false);
		else
			SetTimer(1, 3000, NULL);

		KillTimer(0);
	}
	else if (nIDEvent == 1) {
		if (rand() % 2 == 1) {
			showRandomChoice(true);
			ShowWindow(SW_HIDE);
			KillTimer(1);

		}
		else {
			CLiveResultDlg* pLiveResultDlg = new CLiveResultDlg();
			pLiveResultDlg->Create(IDD_LIVERESULT_DIALOG);

			CRect parentRect, currentRect;
			GetWindowRect(&parentRect);
			pLiveResultDlg->GetWindowRect(&currentRect);
			pLiveResultDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);
			KillTimer(1);

			DestroyWindow();
		}
	}
	else if (nIDEvent == 3) {
		if (m_currentChatIndex < m_selectedChats.size()) {
			CString chatStr(m_selectedChats[m_currentChatIndex].GetChat().c_str());
			m_cbLiveChat.AddString(chatStr);

			m_currentChatIndex++;
		}
		else {
			KillTimer(3);
		}
	}
	

	CDialogEx::OnTimer(nIDEvent);
}


void CLiveDlg::showRandomChoice(bool _afterLive)
{
	// TODO: 여기에 구현 코드 추가.
	CRandomChoiceDlg* pRandomChoiceDlg = new CRandomChoiceDlg();
	pRandomChoiceDlg->Create(IDD_RANDOMCHOICE_DIALOG);
	pRandomChoiceDlg->m_bAfterLive = _afterLive;
	pRandomChoiceDlg->setParentDialog(this);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pRandomChoiceDlg->GetWindowRect(&currentRect);
	pRandomChoiceDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);
}

HBRUSH CLiveDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	if (nCtlColor == CTLCOLOR_LISTBOX) {
		if (pWnd->GetDlgCtrlID() == IDC_LIVE_CHAT) {
			// Change text color
			pDC->SetTextColor(RGB(0, 0, 0)); // Yellow text

			// Change background color
			pDC->SetBkColor(RGB(200, 200, 200));

			// Use a brush to set the background color
			static CBrush brush(RGB(200, 200, 200));
			return (HBRUSH)brush.GetSafeHandle();
		}
	}

	// Default handling for other controls
	return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}



BOOL CLiveDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}
