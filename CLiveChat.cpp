#include "pch.h"
#include "CLiveChat.h"
#include "Player.h"

std::vector<CLiveChat> CLiveChat::LiveChating = {
    CLiveChat("대유잼", true),
    CLiveChat("!!!!!!!", true),
    CLiveChat("ㅋㅋㅋㅋㅋㅋㅋㅋ", true),
    CLiveChat("너무 웃겨요 ㅋㅋㅋㅋ 진짜 오늘 힐링하고 갑니다!", true),
    CLiveChat("이런 컨텐츠 너무 좋아요~ 계속 해주세요!", true),
    CLiveChat("이거지예", true),
    CLiveChat("아 진짜 ㅋㅋㅋㅋㅋ 너무 웃겨!", true),
    CLiveChat("당장 팔로우 하러 가야겠다", true),
    CLiveChat("오늘 방송 레전드네 ㅋㅋㅋㅋ", true),
    CLiveChat("이건 유튭각이다", true),
    CLiveChat("ㅋㅋㅋㅋㅋ", true),
    CLiveChat("별로네...", false),
    CLiveChat("요즘 감 잃었네", false),
    CLiveChat("이건 좀...", false),
    CLiveChat("분위기 파악 좀", false),
    CLiveChat("이게 그 정돈가", false),
    CLiveChat(".......", false),
    CLiveChat("다른 얘기하면 안돼요?", false),
    CLiveChat("흠....", false),
    CLiveChat("뇌절 그만", false),
    CLiveChat("초심 잃으신 것 같은데", false)
};

CLiveChat::CLiveChat(const std::string& chat, bool positive)
    : chat(chat), positive(positive) {}

std::string CLiveChat::GetChat() const {
    return chat;
}

bool CLiveChat::IsPositive() const {
    return positive;
}

std::vector<CLiveChat> CLiveChat::GetRandomChats(bool positive, int count)
{
#ifdef DEBUG
    CString debug;
    debug.Format(_T("%s"), Player::instance.GetName());
    OutputDebugString(debug);
#endif
    std::vector<CLiveChat> filteredChats;
    for (const auto& chat : LiveChating)
    {
        if (chat.IsPositive() == positive)
        {
            filteredChats.push_back(chat);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(filteredChats.begin(), filteredChats.end(), gen);

    if (filteredChats.size() > count)
    {
        filteredChats.resize(count);
    }

    return filteredChats;
}


