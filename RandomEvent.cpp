#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("���� ä��â�� ���� �ʹ� �� �Ѵ� �е��� �־ ���� ������... �׷� ä���� ���� ��� �ؾ� �������? �����ϰ� ����ؾ� �ұ��, �ƴϸ� �׳� ���ϰ� �Ѿ�� �ұ��?", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 10, -100, -100, -100, 1000, 1000, 100));
	liveRandomEvents.push_back(RandomEvent("��ؿ�! ���� �ʹ� �ų��� �׸�... ���Ǽ��� �ع��Ⱦ��! �����... �̰� �׳� ��½ �Ѿ�� �ұ��, �ƴϸ� �����ϰ� ����� ����� �ұ��? ����, ȥ����������", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 10, -100, -100, -100, 1000, 1000, 100));
    liveRandomEvents.push_back(RandomEvent("��� �߿� ���� �̼��ε�... �ʹ� �����ؼ� ����������. �̰� �ؾ� �ұ�, ���ƾ� �ұ�... ���� �ߴٰ� �̻������� �� ������ �ǰ�... ��εǳ�.", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 10, -100, -100, -100, 1000, 1000, 100));
    liveRandomEvents.push_back(RandomEvent("��!!! 10���� �Ŀ��̶��!!! ������, �� �̷��� ū �� �޾Ƶ� �Ǵ� �ſ���?! �ʹ� �����մϴ�!!! (���ΰ� �̸�)��!!! (���ΰ� �̸�)��!!!", "ȭ�� �´��� �ν��� ��������.", "�׳� �����ߴ�. ���� ���ش� ����.", 0, 10, -100, -100, -100, 1000, 1000, 100));
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