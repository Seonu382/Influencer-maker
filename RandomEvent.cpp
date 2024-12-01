#include "pch.h"
#include "RandomEvent.h"
#include <iostream>

#define ON_AIR 0
#define AFTER_LIVE 1;

std::vector<RandomEvent> RandomEvent::liveRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("어떡하지... 내가 너무 신나서 그만 말실수를 해버렸네. 이걸 그냥 얼버무리고 넘어가야 할까, 아니면 사과를 해야 할까... 아, 진짜 당황스러워.",
        "딱히 아무 일도 없었어..", "헉.. 내 사과가 오히려 논란이 되었어",
        "얼버무린다", "사과하고 넘어간다",
        ON_AIR, 10,
        0, 0, 0,
        -3, 0, 0));
	liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 선 넘는 사람들이 많아져서 너무 스트레스 받는다. 이걸 어떻게 대처해야 하지? 강하게 얘기해야 하나... 아니면 그냥 무시해야 하나... 고민이다.",
        "어떡해.. 내가 너무 과잉반응 해버렸나봐,, 반응이 안좋아", "딱히 아무 일도 없었어.. 그런데 마음이 아프다.",
        "강하게 얘기한다", "무시하고 넘어간다",
        ON_AIR, 10,
        -3, 0, 0,
        0, 0, -2));
    liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 선 넘는 사람들이 많아져서 너무 스트레스 받는다. 이걸 어떻게 대처해야 하지? 강하게 얘기해야 하나... 아니면 그냥 무시해야 하나... 고민이다.",
        "강하게 말하니까 사이다라고 사람들이 좋아해!", "딱히 아무 일도 없었어.. 그런데 마음이 아프다.",
        "강하게 얘기한다", "무시하고 넘어간다",
        ON_AIR, 10,
        3, 0, 0,
        0, 0, -2));
    liveRandomEvents.push_back(RandomEvent("챌린지 찍는 게 요즘 유행이니까 나도 한번 해볼까 싶다. 지금 두 가지 아이디어가 있는데... 둘 다 재밌어 보이는데 뭘 해야 할지 고민이다. 한 가지를 골라야 하는데... 🤔",
        "반응이 별로야..", "반응이 좋은데!",
        "A 챌린지", "B 챌린지",
        ON_AIR, 10,
        2, 0, 0,
        7, 0, 0));
    liveRandomEvents.push_back(RandomEvent("내가 그냥 재미있게 하려고 했던 건데... 이게 이렇게 심각해질 줄 몰랐네. 사람들이 오해하면 어떡하지... 아, 이걸 어떻게 수습해야 할지 모르겠다. 진짜 고민이다.",
        "주작 잘 대처", "주작 못 대처",
        "주작 잘 대처", "주작 못 대처",
        ON_AIR, 10,
        -2, 0, 0,
        -7, 0, 0));
    liveRandomEvents.push_back(RandomEvent("방송 중에 들어온 미션인데... 너무 엉뚱해서 망설여진다. 이걸 해야 할까, 말아야 할까... 괜히 했다가 이상해질까 봐 걱정도 되고... 고민되네.",
        "미션 못 대처", "미션 잘 대처",
        "미션 못 대처", "미션 잘 대처",
        ON_AIR, 10,
        10, -10, 0,
        10, 10, 0));
    liveRandomEvents.push_back(RandomEvent("이렇게 많은 사랑을 받고 있으니까 나도 뭔가 의미 있는 일을 해야겠다는 생각이 든다. 음... 그래, 기부를 하면 어떨까? 이게 가장 좋은 방법일 것 같아.",
        "지출은 많았지만 팔로워를 얻었다", "딱히 아무 일도 없었어",
        "기부 이벤트를 진행한다", "기부 이벤트를 진행하지 않는다",
        ON_AIR, 10,
        30, 30, 0,
        0, 0, 0));
    liveRandomEvents.push_back(RandomEvent("헉... 도네이션을 받았어... 이거 너무 큰 금액이야",
        "도네이션으로 돈을 벌었어", "도네이션으로 돈을 벌었어",
        "확인", "확인",
        ON_AIR, 10,
        0, 10, 0,
        0, 10, 0));
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