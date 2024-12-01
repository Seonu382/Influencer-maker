#include "pch.h"
#include "CLiveChat.h"
#include "Player.h"

std::string p1 = Player::instance.GetName() + std::string(CT2A(_T("님 오늘 폼미쳤다!!")));;

std::vector<CLiveChat> CLiveChat::LiveChating = {
    CLiveChat("대유잼", true),
    CLiveChat(p1, true),
    CLiveChat("ㅋㅋㅋㅋㅋㅋㅋㅋ", true),
    CLiveChat("너무 웃겨요 ㅋㅋㅋㅋ 진짜 오늘 힐링하고 갑니다!", true),
    CLiveChat("이런 컨텐츠 너무 좋아요~ 계속 해주세요!", true),
    CLiveChat("이거지예", true),
    CLiveChat(Player::instance.GetName() + " 아 진짜 ㅋㅋㅋㅋ", true),
    CLiveChat("노잼", false),
    CLiveChat("감다뒤", false),
    CLiveChat("이건 좀...", false),
    CLiveChat("분위기 파악 좀", false)
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


