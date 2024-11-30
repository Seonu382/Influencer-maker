#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("채팅이 자꾸 선을 넘는다. 화를 낼까?", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
}

RandomEvent RandomEvent::GetLiveRandomEvent() {
	int totalProbability = 0;
	for (const auto& event : liveRandomEvents) {
		totalProbability += event.GetProbability();
	}

	int randomValue = rand() / RAND_MAX * totalProbability;

	int cumulativeProbability = 0;
	for (const auto& event : liveRandomEvents) {
		cumulativeProbability += event.GetProbability();
		if (randomValue <= cumulativeProbability) {
			return event;
		}
	}

	return liveRandomEvents[0];
}