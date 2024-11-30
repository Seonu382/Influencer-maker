#pragma once
#include <string>

#define NOLIVE 0
#define GAME 1
#define TALK 2
#define MUKBANG 3
#define BEAUTY 4
#define EXERCISE 5

class Player {
private:
	std::string name;
	
	int day;
	int currentTheme;

	int follower;
	int health;
	int money;

	int previousFollower;
	int previousHealth;
	int previousMoney;

	int game;
	int talk;
	int mukbang;
	int beauty;
	int exercise;

public:
	Player() : name("¿µÈñ"), day(1), follower(0), health(100), money(0),
	game(1), talk(1), mukbang(1), beauty(1), exercise(1)
	{}

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

	void SetGame(const int& _game) { game = _game; }
	int GetGame() const { return game; }

	void SetTalk(const int& _talk) { talk = _talk; }
	int GetTalk() const { return talk; }

	void SetMukbang(const int& _mukbang) { mukbang = _mukbang; }
	int GetMukbang() const { return mukbang; }

	void SetBeauty(const int& _beauty) { beauty = _beauty; }
	int GetBeauty() const { return beauty; }

	void SetExercise(const int& _exercise) { exercise = _exercise; }
	int GetExercise() const { return exercise; }

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


	static Player instance;
};