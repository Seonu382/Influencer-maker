#include "pch.h"
#include "CLiveChat.h"
#include "Player.h"

std::vector<CLiveChat> CLiveChat::LiveChating;

CLiveChat::CLiveChat(const std::string& chat, bool positive)
    : chat(chat), positive(positive) {}

std::string CLiveChat::GetChat() const {
    return chat;
}

bool CLiveChat::IsPositive() const {
    return positive;
}

void CLiveChat::InitializeLiveChat() {
    LiveChating.push_back(CLiveChat("������", true));
    LiveChating.push_back(CLiveChat(Player::instance.GetName() + "�� �ߺ��� �־��!", true));
    LiveChating.push_back(CLiveChat("����������������", true));
    LiveChating.push_back(CLiveChat("�ʹ� ���ܿ� �������� ��¥ ���� �����ϰ� ���ϴ�!", true));
    LiveChating.push_back(CLiveChat("�̷� ������ �ʹ� ���ƿ�~ ��� ���ּ���!", true));
    LiveChating.push_back(CLiveChat("�̰�����", true));
    LiveChating.push_back(CLiveChat("�� ��¥ ���������� �ʹ� ����!", true));
    LiveChating.push_back(CLiveChat("���� �ȷο� �Ϸ� ���߰ڴ�", true));
    LiveChating.push_back(CLiveChat("���� ��� ������� ��������", true));
    LiveChating.push_back(CLiveChat("�̰� ���Z���̴�", true));
    LiveChating.push_back(CLiveChat("����������", true));
    LiveChating.push_back(CLiveChat("���γ�...", false));
    LiveChating.push_back(CLiveChat("���� �� �Ҿ���", false));
    LiveChating.push_back(CLiveChat("�̰� ��...", false));
    LiveChating.push_back(CLiveChat("������ �ľ� ��", false));
    LiveChating.push_back(CLiveChat("�̰� �� ������", false));
    LiveChating.push_back(CLiveChat(".......", false));
    LiveChating.push_back(CLiveChat("�ٸ� ����ϸ� �ȵſ�?", false));
    LiveChating.push_back(CLiveChat("��....", false));
    LiveChating.push_back(CLiveChat("���� �׸�", false));
    LiveChating.push_back(CLiveChat("�ʽ� ������ �� ������", false));
}

std::vector<CLiveChat> CLiveChat::GetRandomChats(bool positive, int count)
{
#ifdef DEBUG
    CString debug(Player::instance.GetName().c_str());
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


