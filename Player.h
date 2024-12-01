#pragma once
#include <string>

#define NOLIVE 0
#define GAME 1
#define TALK 2
#define MUKBANG 3
#define BEAUTY 4
#define EXERCISE 5

#define NORMAL 0
#define GWANGGO 1
#define HABBANG 2
#define SACHE 3

#define NOTAPPEAR 0;
#define DENY -1
#define ACCEPT 1

#define CAMERA 0
#define COMPUTER 1
#define EDITOR 2

class Player {
private:
	std::string name;
	
	int day;
	int currentTheme;

	int follower;
	int money;
	int health;

	int previousFollower;
	int previousHealth;
	int previousMoney;

	int nextDayTrend;

	int game;
	int talk;
	int mukbang;
	int beauty;
	int exercise;

	int nextGame;
	int nextTalk;
	int nextMukbang;
	int nextBeauty;
	int nextExercise;

	bool shopItem[3];

	int skilledGame;
	int skilledTalk;
	int skilledMukbang;
	int skilledBeauty;
	int skilledExercise;

	//mainEvent

	int mainEvent[4];

public:
	Player() : name("¿µÈñ"), day(1), follower(100), money(100), health(100),
		game(1), talk(1), mukbang(1), beauty(1), exercise(1),
		skilledGame(0), skilledTalk(0), skilledMukbang(0), skilledBeauty(0), skilledExercise(0)
	{
		for (int i = 0; i < 3; i++) {
			shopItem[i] = false;
		}
		for (int i = 0; i < 4; i++) {
			mainEvent[i] = 0;
		}
	}

	static void InitializePlayerStat();

	void SetName(const std::string _name) { name = _name; }
	std::string GetName() const { return name; }

	void SetDay(const int& _day) { day = _day; }
	int GetDay() const { return day; }
	void AddDay() { day++; }

	void SetFollower(const int& _follower) { follower = _follower; }
	int GetFollower() const { return follower; }
	void AddFollower(int _add) {
		if (follower + _add >= 0) {
			follower += _add;
		}
		else follower = 0;
	}

	void SetMoney(const int& _money) { money = _money; }
	int GetMoney() const { return money; }
	void AddMoney(int _add) {
		if (money + _add >= 0) {
			money += _add;
		}
		else money = 0;
	}

	void SetHealth(const int& _health) { health = _health; }
	int GetHealth() const { return health; }
	void AddHealth(int _add) {
		if (health + _add >= 0) {
			health += _add;
		}
		else health = 0;
	}

	void SetTrend(const int& _trend) { nextDayTrend = _trend; }
	int GetTrend() const { return nextDayTrend; }

	void SetGame(const int& _game) { game = _game; }
	void SetTalk(const int& _talk) { talk = _talk; }
	void SetMukbang(const int& _mukbang) { mukbang = _mukbang; }
	void SetBeauty(const int& _beauty) { beauty = _beauty; }
	void SetExercise(const int& _exercise) { exercise = _exercise; }

	int GetGame() const { return game; }
	int GetTalk() const { return talk; }
	int GetMukbang() const { return mukbang; }
	int GetBeauty() const { return beauty; }
	int GetExercise() const { return exercise; }

	void SetNextGame(const int& _nextGame) { nextGame = _nextGame; }
	void SetNextTalk(const int& _nextTalk) { nextTalk = _nextTalk; }
	void SetNextMukbang(const int& _nextMukbang) { nextMukbang = _nextMukbang; }
	void SetNextBeauty(const int& _nextBeauty) { nextBeauty = _nextBeauty; }
	void SetNextExercise(const int& _nextExercise) { nextExercise = _nextExercise; }

	int GetNextGame() const { return nextGame; }
	int GetNextTalk() const { return nextTalk; }
	int GetNextMukbang() const { return nextMukbang; }
	int GetNextBeauty() const { return nextBeauty; }
	int GetNextExercise() const { return nextExercise; }

	void SkilledGame() { skilledGame += 2; }
	void SkilledTalk() { skilledTalk += 2; }
	void SkilledMukbang() { skilledMukbang += 2; }
	void SkilledBeauty() { skilledBeauty += 2; }
	void SkilledExercise() { skilledExercise += 2; }

	void SetSkilledGame(const int& _skilledGame) { skilledGame = _skilledGame; }
	void SetSkilledTalk(const int& _skilledTalk) { skilledGame = _skilledTalk; }
	void SetSkilledMukbang(const int& _skilledMukbang) { skilledGame = _skilledMukbang; }
	void SetSkilledBeauty(const int& _skilledBeauty) { skilledGame = _skilledBeauty; }
	void SetSkilledExercise(const int& _skilledExercise) { skilledGame = _skilledExercise; }

	int GetSkilledGame() const { return skilledGame; }
	int GetSkilledTalk() const { return skilledTalk; }
	int GetSkilledMukbang() const { return skilledMukbang; }
	int GetSkilledBeauty() const { return skilledBeauty; }
	int GetSkilledExercise() const { return skilledExercise; }

	void SetCurrentTheme(const int& _theme) { currentTheme = _theme; }
	int GetCurrentTheme() const { return currentTheme; }

	void UpdatePreviousStasis() {
		previousFollower = follower;
		previousMoney = money;
		previousHealth = health;
	}
	int GetPreviousFollower() const { return previousFollower; }
	int GetPreviousMoney() const { return previousMoney; }
	int GetPreviousHealth() const { return previousHealth; }


	// mainEvent

	void SetMainEvent(int id, int _status) { mainEvent[id] = _status; }
	int GetMainEvent(int id) const { return mainEvent[id]; }

	void SetShopItem(int id, bool _bool) { shopItem[id] = _bool; }
	bool GetShopItem(int id) const { return shopItem[id]; }


	static Player instance;
};