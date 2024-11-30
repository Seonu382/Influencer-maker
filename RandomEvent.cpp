#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("ä���� �ڲ� ���� �Ѵ´�. ȭ�� ����?", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 10, -100, -100, -100, 1000, 1000, 100));
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