#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("���� ä��â�� ���� �ʹ� �� �Ѵ� �е��� �־ ���� ������... �׷� ä���� ���� ��� �ؾ� �������? �����ϰ� ����ؾ� �ұ��, �ƴϸ� �׳� ���ϰ� �Ѿ�� �ұ��?", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 20, -1, 0, 0, 0, 0, 0));
	liveRandomEvents.push_back(RandomEvent("Yes�� ������ No�� ��������", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 10, 100, 100, 10, -80, -50, -20));
}

RandomEvent RandomEvent::GetLiveRandomEvent() {
    int totalProbability = 0;
    for (const auto& event : liveRandomEvents) {
        totalProbability += event.GetProbability();
    }

    if (totalProbability == 0) {
        throw std::runtime_error("Total probability is zero, unable to select a random event.");
    }

    int randomValue = rand() % totalProbability;

    int cumulativeProbability = 0;
    for (const auto& event : liveRandomEvents) {
        cumulativeProbability += event.GetProbability();
        if (randomValue < cumulativeProbability) {
            return event;
        }
    }

    throw std::logic_error("Failed to select a random event despite valid probabilities.");
}