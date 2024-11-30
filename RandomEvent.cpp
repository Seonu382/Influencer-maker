#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 가끔 너무 선 넘는 분들이 있어서 조금 힘들어요... 그런 채팅은 제가 어떻게 해야 좋을까요? 진지하게 얘기해야 할까요, 아니면 그냥 쿨하게 넘어가야 할까요?", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
	liveRandomEvents.push_back(RandomEvent("어떡해요! 제가 너무 신나서 그만... 말실수를 해버렸어요! 어떡하지... 이걸 그냥 슬쩍 넘어가야 할까요, 아니면 진지하게 사과를 드려야 할까요? 으앙, 혼란스러워요", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
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