#pragma once
#include <string>
#include <iostream>

class Dialogue
{
private:
	char dialogue;
	char choice;
public:
	void LeaveBossFight();
	void TalkToSuperiorBeforeCastleGuards();
	void intro();
	void introHint();
	void CastleGuardTalk();
	void MeetSuperiorFirstTime();
	void BeatSuperiorFirstTime();
	void MeetBoss();
	void DefeatBoss();
	void Dead();
	int speed;

};

