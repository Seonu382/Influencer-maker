#include "pch.h"
#include "CLiveChat.h"

std::vector<CLiveChat> CLiveChat::LiveChating = {
    CLiveChat("대유잼", true),
    CLiveChat("폼미쳤다", true),
    CLiveChat("ㅋㅋㅋㅋㅋㅋㅋㅋ", true),
    CLiveChat("이거지예", true),
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


