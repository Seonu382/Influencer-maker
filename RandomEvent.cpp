#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 가끔 너무 선 넘는 분들이 있어서 조금 힘들어요... 그런 채팅은 제가 어떻게 해야 좋을까요? 진지하게 얘기해야 할까요, 아니면 그냥 쿨하게 넘어가야 할까요?", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 20, -1, 0, 0, 0, 0, 0));
	liveRandomEvents.push_back(RandomEvent("Yes시 좋은거 No시 안좋은거", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, 100, 100, 10, -80, -50, -20));
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