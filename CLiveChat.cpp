#include "pch.h"
#include "CLiveChat.h"

std::vector<CLiveChat> CLiveChat::LiveChating = {
    CLiveChat("������", true),
    CLiveChat("�����Ƶ�", true),
    CLiveChat("����", false),
    CLiveChat("���ٵ�", false)
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


