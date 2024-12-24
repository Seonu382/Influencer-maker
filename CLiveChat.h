#pragma once
#include <string>
#include <vector>
#include <random>

class CLiveChat
{
private:
    std::string chat;   
    bool positive;       


public:
    CLiveChat() : chat(""), positive(false) {}
    CLiveChat(const std::string& chat, bool positive);

    std::string GetChat() const;
    bool IsPositive() const;

    static std::vector<CLiveChat> GetRandomChats(bool positive, int count);

    static std::vector<CLiveChat> LiveChating;
    static void InitializeLiveChat();
};

// Hello
