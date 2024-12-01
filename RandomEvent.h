#pragma once
#include <string>
#include <vector>

class RandomEvent {
private:
	std::string eventDescription;
	std::string yesDescription;
	std::string noDescription;

	std::string yesButton;
	std::string noButton;

	int eventType;
	int probability;

	int yesFollower;
	int yesMoney;
	int yesHealth;

	int noFollower;
	int noMoney;
	int noHealth;

	static std::vector<RandomEvent> liveRandomEvents;

public:
	RandomEvent() {}
	RandomEvent(std::string _eventDescription, std::string _yesDescription, std::string _noDescription, 
		std::string _yesButton, std::string _noButton,
		int _eventType, int _probability,
		int _yesFollower, int _yesMoney, int _yesHealth,
		int _noFollower, int _noMoney, int _noHealth)
		: eventDescription(_eventDescription), yesDescription(_yesDescription), noDescription(_noDescription), 
		yesButton(_yesButton), noButton(_noButton),
		eventType(_eventType), probability(_probability),
		yesFollower(_yesFollower), yesMoney(_yesMoney), yesHealth(_yesHealth),
		noFollower(_noFollower), noMoney(_noMoney), noHealth(_noHealth) {}

	std::string GetEventDescription() const { return eventDescription; }
	std::string GetYesDescription() const { return yesDescription; }
	std::string GetNoDescription() const { return noDescription; }

	std::string GetYesButton() const { return yesButton; }
	std::string GetNoButton() const { return noButton; }

	int GetProbability() const { return probability; }

	int GetYesFollower() const { return yesFollower; }
	int GetYesMoney() const { return yesMoney; }
	int GetYesHealth() const { return yesHealth; }

	int GetNoFollower() const { return noFollower; }
	int GetNoMoney() const { return noMoney; }
	int GetNoHealth() const { return noHealth; }

	static void InitializeDatabase();

	static RandomEvent GetLiveRandomEvent();
};