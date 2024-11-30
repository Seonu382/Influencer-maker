#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 가끔 너무 선 넘는 분들이 있어서 조금 힘들어요... 그런 채팅은 제가 어떻게 해야 좋을까요? 진지하게 얘기해야 할까요, 아니면 그냥 쿨하게 넘어가야 할까요?", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
	liveRandomEvents.push_back(RandomEvent("어떡해요! 제가 너무 신나서 그만... 말실수를 해버렸어요! 어떡하지... 이걸 그냥 슬쩍 넘어가야 할까요, 아니면 진지하게 사과를 드려야 할까요? 으앙, 혼란스러워요", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
    liveRandomEvents.push_back(RandomEvent("방송 중에 들어온 미션인데... 너무 엉뚱해서 망설여진다. 이걸 해야 할까, 말아야 할까... 괜히 했다가 이상해질까 봐 걱정도 되고... 고민되네.", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
    liveRandomEvents.push_back(RandomEvent("헉!!! 10만원 후원이라니!!! 여러분, 저 이렇게 큰 거 받아도 되는 거예요?! 너무 감사합니다!!! (주인공 이름)업!!! (주인공 이름)업!!!", "화를 냈더니 민심이 나빠졌다.", "그냥 무시했다. 딱히 피해는 없다.", 0, 10, -100, -100, -100, 1000, 1000, 100));
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