#pragma once
#include <string>
#include <iostream>

class Dialogue
{
private:
	char dialogue;
	char choice;
public:
	void notallowed();
	void intro();
	void introHint();
	void CastleGuardTalk();
	void MeetSuperiorFirstTime();
	void BeatSuperiorFirstTime();
	void MeetBoss();
	void DefeatBoss();
	int speed;

};

