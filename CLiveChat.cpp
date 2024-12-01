#include "pch.h"
#include "CLiveChat.h"
#include "Player.h"

std::vector<CLiveChat> CLiveChat::LiveChating = {
    CLiveChat("������", true),
    CLiveChat("!!!!!!!", true),
    CLiveChat("����������������", true),
    CLiveChat("�ʹ� ���ܿ� �������� ��¥ ���� �����ϰ� ���ϴ�!", true),
    CLiveChat("�̷� ������ �ʹ� ���ƿ�~ ��� ���ּ���!", true),
    CLiveChat("�̰�����", true),
    CLiveChat("�� ��¥ ���������� �ʹ� ����!", true),
    CLiveChat("���� �ȷο� �Ϸ� ���߰ڴ�", true),
    CLiveChat("���� ��� ������� ��������", true),
    CLiveChat("�̰� ���Z���̴�", true),
    CLiveChat("����������", true),
    CLiveChat("���γ�...", false),
    CLiveChat("���� �� �Ҿ���", false),
    CLiveChat("�̰� ��...", false),
    CLiveChat("������ �ľ� ��", false),
    CLiveChat("�̰� �� ������", false),
    CLiveChat(".......", false),
    CLiveChat("�ٸ� ����ϸ� �ȵſ�?", false),
    CLiveChat("��....", false),
    CLiveChat("���� �׸�", false),
    CLiveChat("�ʽ� ������ �� ������", false)
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


