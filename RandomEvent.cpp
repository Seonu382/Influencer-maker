#include "pch.h"
#include "RandomEvent.h"
#include "Player.h"
#include <iostream>

std::vector<RandomEvent> RandomEvent::liveRandomEvents;
std::vector<RandomEvent> RandomEvent::afterRandomEvents;

void RandomEvent::InitializeDatabase() {
	liveRandomEvents.push_back(RandomEvent("어떡하지... 내가 너무 신나서 그만 말실수를 해버렸네. 이걸 그냥 얼버무리고 넘어가야 할까, 아니면 사과를 해야 할까... 아, 진짜 당황스러워.",
        "딱히 아무 일도 없었어..", "헉.. 내 사과가 오히려 논란이 되었어",
        "얼버무린다", "사과하고 넘어간다",
        NORMAL, 10,
        0, 0, 0,
        -3, 0, 0));
	liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 선 넘는 사람들이 많아져서 너무 스트레스 받는다. 이걸 어떻게 대처해야 하지? 강하게 얘기해야 하나... 아니면 그냥 무시해야 하나... 고민이다.",
        "어떡해.. 내가 너무 과잉반응 해버렸나봐,, 반응이 안좋아", "딱히 아무 일도 없었어.. 그런데 마음이 아프다.",
        "강하게 얘기한다", "무시하고 넘어간다",
        NORMAL, 10,
        -3, 0, 0,
        0, 0, -2));
    liveRandomEvents.push_back(RandomEvent("요즘 채팅창에 선 넘는 사람들이 많아져서 너무 스트레스 받는다. 이걸 어떻게 대처해야 하지? 강하게 얘기해야 하나... 아니면 그냥 무시해야 하나... 고민이다.",
        "강하게 말하니까 사이다라고 사람들이 좋아해!", "딱히 아무 일도 없었어.. 그런데 마음이 아프다.",
        "강하게 얘기한다", "무시하고 넘어간다",
        NORMAL, 10,
        3, 0, 0,
        0, 0, -2));
    liveRandomEvents.push_back(RandomEvent("챌린지 찍는 게 요즘 유행이니까 나도 한번 해볼까 싶다. 지금 두 가지 아이디어가 있는데... 둘 다 재밌어 보이는데 뭘 해야 할지 고민이다. 한 가지를 골라야 하는데... 🤔",
        "반응이 별로야..", "반응이 좋은데!",
        "A 챌린지", "B 챌린지",
        NORMAL, 10,
        2, 0, 0,
        7, 0, 0));
    liveRandomEvents.push_back(RandomEvent("내가 그냥 재미있게 하려고 했던 건데... 이게 이렇게 심각해질 줄 몰랐네. 사람들이 오해하면 어떡하지... 아, 이걸 어떻게 수습해야 할지 모르겠다. 진짜 고민이다.",
        "주작 잘 대처", "주작 못 대처",
        "주작 잘 대처", "주작 못 대처",
        NORMAL, 10,
        -2, 0, 0,
        -7, 0, 0));
    liveRandomEvents.push_back(RandomEvent("방송 중에 들어온 미션인데... 너무 엉뚱해서 망설여진다. 이걸 해야 할까, 말아야 할까... 괜히 했다가 이상해질까 봐 걱정도 되고... 고민되네.",
        "미션 못 대처", "미션 잘 대처",
        "미션 못 대처", "미션 잘 대처",
        NORMAL, 10,
        10, -10, 0,
        10, 10, 0));
    liveRandomEvents.push_back(RandomEvent("이렇게 많은 사랑을 받고 있으니까 나도 뭔가 의미 있는 일을 해야겠다는 생각이 든다. 음... 그래, 기부를 하면 어떨까? 이게 가장 좋은 방법일 것 같아.",
        "지출은 많았지만 팔로워를 얻었다", "딱히 아무 일도 없었어",
        "기부 이벤트를 진행한다", "기부 이벤트를 진행하지 않는다",
        NORMAL, 10,
        30, 30, 0,
        0, 0, 0));
    liveRandomEvents.push_back(RandomEvent("헉... 도네이션을 받았어... 이거 너무 큰 금액이야",
        "도네이션으로 돈을 벌었어", "도네이션으로 돈을 벌었어",
        "확인", "확인",
        NORMAL, 10,
        0, 10, 0,
        0, 10, 0));

    afterRandomEvents.push_back(RandomEvent("사생활 논란이 생겨서 지금 정말 고민 중이야. 처음엔 그냥 지나가겠지 했는데, 점점 더 커지는 것 같아서 불안해.",
        "해명을 했더니 사람들이 나의 입장을 알아봐줬어", "해명을 안했더니 사람들이 내가 정말 나쁜사람인줄 아는거같아",
        "해명한다", "해명하지 않는다",
        NORMAL, 10,
        -2, 0, 0,
        -7, 0, 0));
    afterRandomEvents.push_back(RandomEvent("방송 끝나고 싸인 요청이 진짜 많이 들어오고 있어. 팬분들이 나를 좋아해주시는 건 정말 감사한 일이지만, 이렇게 많은 요청을 받으니까 조금 힘들어.",
        "모두에게 싸인을 해줬어. 힘들지만 나를 이렇게 많이 좋아해줘서 기뻐", "싸인을 안해줬더니 민심이 안좋아졌어",
        "모두에게 싸인을 해준다", "모른척하고 지나간다",
        NORMAL, 10,
        7, 0, -2,
        -5, 0, 0));
    afterRandomEvents.push_back(RandomEvent("팔로워의 선물이 도착했는데, 혼자서 열어볼까 말까 고민하고 있어.",
        "결국 열기로 결정했어,팔로워가 나를 위해 준비해준 선물이니까, 그 마음을 소중히 여기는 게 맞는 것 같아.", "결국 안 열어보기로 결정했어. 고민 끝에, 지금은 그냥 열지 않는 게 나을 것 같다는 생각이 들었거든.",
        "선물을 연다", "선물을 열지 않는다",
        NORMAL, 10,
        0, 10, -2,
        0, 0, 0));
    afterRandomEvents.push_back(RandomEvent("감기몸살 때문에 정말 힘든 상황이야. 몸이 축 쳐지고 열도 나서 방송을 할지 말지 고민하고 있어. 팬들과 소통하고 싶긴 한데, 이렇게 아픈 상태로는 제대로 방송할 자신이 없어.",
        "정말 힘들었지만 오늘 컨텐츠가 좋아서 다들 반응이 좋았어!", "오늘 방송은 대충했어.. 도저히 힘들어서 버틸수 없었어",
        "버티고 방송하기", "쉬엄쉬엄 방송하기",
        NORMAL, 10,
        10, 0, -3,
        -5, 0, 0));

}

RandomEvent RandomEvent::GetLiveRandomEvent() {

    if (!Player::instance.GetMainEvent(HABBANG) && Player::instance.GetFollower() >= 5'000 && Player::instance.GetDay() >= 10 ) {
        return RandomEvent("헉... 진짜 나한테 이런 제안이 올 줄이야. 요즘 완전 핫한 인플루언서분인데, 나 그분 방송 가끔 몰래 보기도 했는데... 이걸 받아야 하나 말아야 하나... 고민되네. 😣",
            "합방을 수락했다", "합방을 거절했다",
            "합방을 수락한다", "합방을 거절한다",
            HABBANG, 0,
            20, 10, 0,
            0, 0, 0
        );
    }

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

RandomEvent RandomEvent::GetAfterRandomEvent() {
    if (!Player::instance.GetMainEvent(GWANGGO) && Player::instance.GetFollower() >= 10'000 && Player::instance.GetDay() >= 15) {
        return RandomEvent("요즘 뒷광고 제의를 하나 받았는데, 지금 정말 고민 중이야. 솔직히 돈이 꽤 많이 들어오긴 하는데, 양심이 계속 나를 괴롭혀. 이런 걸 하면 시청자들에게 신뢰를 잃을까 봐 걱정이야",
            "뒷광고를 하기로 결정했어", "역시 뒷광고는 아닌거같아,,",
            "뒷광고 하기", "뒷광고 거절",
            GWANGGO, 0,
            5, 40, 0,
            0, 0, 0);
    }
    else if (!Player::instance.GetMainEvent(SACHE) && Player::instance.GetDay() >= 25) {
        return RandomEvent("사채업자에게 빚을 갚아야 하는 상황이야. 정말 아쉬운 마음이 크네, , 그동안의 선택들이 후회스러워.",
            "이자를 갚았다", "이자를 갚았다",
            "이자를 갚는다", "이자를 갚는다",
            SACHE, 0,
            0, -40, 0,
            0, -40, 0);
    }

    int totalProbability = 0;
    for (const auto& event : afterRandomEvents) {
        totalProbability += event.GetProbability();
    }

    if (totalProbability == 0) {
        throw std::runtime_error("Total probability is zero, unable to select a random event.");
    }

    int randomValue = rand() % totalProbability;

    int cumulativeProbability = 0;
    for (const auto& event : afterRandomEvents) {
        cumulativeProbability += event.GetProbability();
        if (randomValue < cumulativeProbability) {
            return event;
        }
    }

    throw std::logic_error("Failed to select a random event despite valid probabilities.");
}