#include "pch.h"
#include "Player.h"
#include <iostream>
#include <vector>

Player Player::instance;

void Player::InitializePlayerStat() {
	std::vector<int> stats(5, 0);

	int totalPoint = 15;
	int remainingPoint = totalPoint;

	for (int i = 0; i < 5; ++i)
	{
		stats[i] = 1;
		--remainingPoint;
	}

	while (remainingPoint > 0)
	{
		int randomIndex = rand() % 5; // 0ºÎÅÍ 4±îÁö ·£´ı ÀÎµ¦½º
		stats[randomIndex]++;
		--remainingPoint;
	}

	Player::instance.game = stats[0];
	Player::instance.talk = stats[1];
	Player::instance.mukbang = stats[2];
	Player::instance.beauty = stats[3];
	Player::instance.exercise = stats[4];
}