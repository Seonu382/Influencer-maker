#include "pch.h"
#include "Player.h"
#include <iostream>
#include <vector>

Player Player::instance;

void Player::InitializePlayerStat() {
	srand(static_cast<unsigned int>(time(NULL)));

	CString debug;
	Player::instance.SetTrend((rand() % 5) + 1);

	Player::instance.SetGame(Player::instance.GetNextGame());
	Player::instance.SetTalk(Player::instance.GetNextTalk());
	Player::instance.SetMukbang(Player::instance.GetNextMukbang());
	Player::instance.SetBeauty(Player::instance.GetNextBeauty());
	Player::instance.SetExercise(Player::instance.GetNextExercise());

	
	switch (Player::instance.GetTrend()) {
	case GAME:
		Player::instance.SetNextGame(170 + Player::instance.GetSkilledGame());
		Player::instance.SetNextTalk((rand() % 5) * 10 + 70 + Player::instance.GetSkilledTalk());
		Player::instance.SetNextMukbang((rand() % 5) * 10 + 70 + Player::instance.GetSkilledMukbang());
		Player::instance.SetNextBeauty((rand() % 5) * 10 + 70 + Player::instance.GetSkilledBeauty());
		Player::instance.SetNextExercise((rand() % 5) * 10 + 70 + Player::instance.GetSkilledExercise());
		break;

	case TALK:
		Player::instance.SetNextGame((rand() % 5) * 10 + 70 + Player::instance.GetSkilledGame());
		Player::instance.SetNextTalk(170 + Player::instance.GetSkilledTalk());
		Player::instance.SetNextMukbang((rand() % 5) * 10 + 70 + Player::instance.GetSkilledMukbang());
		Player::instance.SetNextBeauty((rand() % 5) * 10 + 70 + Player::instance.GetSkilledBeauty());
		Player::instance.SetNextExercise((rand() % 5) * 10 + 70 + Player::instance.GetSkilledExercise());
		break;

	case MUKBANG:
		Player::instance.SetNextGame((rand() % 5) * 10 + 70 + Player::instance.GetSkilledGame());
		Player::instance.SetNextTalk((rand() % 5) * 10 + 70 + Player::instance.GetSkilledTalk());
		Player::instance.SetNextMukbang(170 + Player::instance.GetSkilledMukbang());
		Player::instance.SetNextBeauty((rand() % 5) * 10 + 70 + Player::instance.GetSkilledBeauty());
		Player::instance.SetNextExercise((rand() % 5) * 10 + 70 + Player::instance.GetSkilledExercise());
		break;

	case BEAUTY:
		Player::instance.SetNextGame((rand() % 5) * 10 + 70 + Player::instance.GetSkilledGame());
		Player::instance.SetNextTalk((rand() % 5) * 10 + 70 + Player::instance.GetSkilledTalk());
		Player::instance.SetNextMukbang((rand() % 5) * 10 + 70 + Player::instance.GetSkilledMukbang());
		Player::instance.SetNextBeauty(170 + Player::instance.GetSkilledBeauty());
		Player::instance.SetNextExercise((rand() % 5) * 10 + 70 + Player::instance.GetSkilledExercise());
		break;

	case EXERCISE:
		Player::instance.SetNextGame((rand() % 5) * 10 + 70 + Player::instance.GetSkilledGame());
		Player::instance.SetNextTalk((rand() % 5) * 10 + 70 + Player::instance.GetSkilledTalk());
		Player::instance.SetNextMukbang((rand() % 5) * 10 + 70 + Player::instance.GetSkilledMukbang());
		Player::instance.SetNextBeauty((rand() % 5) * 10 + 70 + Player::instance.GetSkilledBeauty());
		Player::instance.SetNextExercise(170 + Player::instance.GetSkilledExercise());
		break;
	}

#ifdef _DEBUG
	debug.Format(_T("Trend : %d\n"), Player::instance.GetTrend());
	OutputDebugString(debug);
	debug.Format(_T("Game : %d\n"), Player::instance.GetNextGame());
	OutputDebugString(debug);
	debug.Format(_T("Talk : %d\n"), Player::instance.GetNextTalk());
	OutputDebugString(debug);	
	debug.Format(_T("Mukbang : %d\n"), Player::instance.GetNextMukbang());
	OutputDebugString(debug);	
	debug.Format(_T("Beauty : %d\n"), Player::instance.GetNextBeauty());
	OutputDebugString(debug);	
	debug.Format(_T("Exercise : %d\n"), Player::instance.GetNextExercise());
	OutputDebugString(debug);

#endif
}