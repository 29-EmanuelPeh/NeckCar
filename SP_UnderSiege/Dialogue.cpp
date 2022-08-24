#include "Dialogue.h"
#include "Character.h"
#include <Windows.h>

void slowPrint(std::string textToPrint, int speed)
{
    int x = 0;
    while (textToPrint[x] != '\0')
    {
        std::cout << textToPrint[x];
        Sleep(speed);
        x++;
    };
}

void Dialogue::notallowed()
{
    slowPrint("I don't need to go here yet.", 10);

    std::cout << std::endl << std::endl;
    system("pause");
}

void Dialogue::intro()
{   
    slowPrint("As a child, your village was destroyed by raiders.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Being the only one alive, you trained and gathered intel for many years to track down and kill the mercenaries who destroyed your village.", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("Fast forward to present times, your intel has located the leader that lead the group of raiders.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Residing in the kingdom of Uraya, the mercenary known as NAME has now become the King's hired mercenary,", 10); Sleep(500); std::cout << std::endl;
    slowPrint("living as a high ranking officer.", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::introHint()
{
    slowPrint("(It's a good idea to lay low for now. I should check out the Castle first.)", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::CastleGuardTalk()
{
    slowPrint("GUARD: Hey you! You can't go in there! It's only for authorized personnel only.", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("PLAYER: How do I get permission? I need to speak to one of the general that goes by the name NAME urgently.", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("GUARD: Hmm", 10); slowPrint(".....", 500); slowPrint("Talk to our superior for access, I think I saw him near the south of the city.", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::MeetSuperiorFirstTime()
{
    slowPrint("PLAYER: Hey! I need to talk to yo-", 10); Sleep(1000); std::cout << std::endl << std::endl;

    slowPrint("SUPERIOR: Hm? Who are you?", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("PLAYER: So you are alive", 10); slowPrint(".....", 500); slowPrint("You are NAME's partner, I remember you.", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("(You pull out your weapon, preparing to fight.)", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::BeatSuperiorFirstTime()
{
    slowPrint("SUPERIOR: Arghh!", 100); Sleep(1000); slowPrint(" I-I remember you now, why are you doing this?", 30); std::cout << std::endl << std::endl;

    slowPrint("PLAYER: ", 10); slowPrint(".....", 500); Sleep(1000); slowPrint("One down, one to go.", 30); Sleep(1000); std::cout << std::endl << std::endl;

    slowPrint("(It's time to find NAME at the Castle.)", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::MeetBoss()
{
    slowPrint("NAME: You..... Its you! You're alive! What.....What have you done!?", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("PLAYER: I finally found you after all these years, I also had to pay your friend a little visit.", 30); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::DefeatBoss()
{
    slowPrint("(NAME falls to the ground beneath you, struggling in pain.)", 30); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("NAME: After what we did", 30); slowPrint(".....", 500); slowPrint("This is how you repay us?", 30); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("PLAYER: What do you mean, you destroyed the village!", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("NAME: No! It was the Goblin's who did it! We tried to saved the village from the Goblin's attack, but we could not win.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Before escaping, I saw a baby crying while in his dead parents arms, and I took him away to a orphanage.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Please", 30); slowPrint(".....", 500); slowPrint("You don't need to do this.", 10); Sleep(2000); std::cout << std::endl;

    std::cout << "Spare Him. (A) or Kill him. (B)" << std::endl;
    std::cin >> choice;
    if (choice == 'A')
    {
        slowPrint("I'm sorry", 30); slowPrint(".....", 500); slowPrint("I-I didn't know. I killed so many.....", 10); std::cout << std::endl << std::endl;

        slowPrint("The deed is done", 30); slowPrint(".....", 500); slowPrint("The dead cannot come back. Run away now kid.", 10); Sleep(2000); std::cout << std::endl << std::endl;

        slowPrint("GOOD ENDING", 100); std::cout << std::endl << std::endl;

        slowPrint("In the end, the player runs away from the kingdom and started his new life as a farmer.", 50); std::cout << std::endl << std::endl;
    }
    else
    {
        slowPrint("(Player kills NAME, avenging his dead family. Not knowing the full truth", 50); slowPrint(".....)", 500); std::cout << std::endl << std::endl;

        slowPrint("(As NAME draws his last breath, Player breaks down crying, for the revenge that he long yearned for", 50); std::cout << std::endl;
        slowPrint("did not grant him peace.", 50); std::cout << std::endl;

        slowPrint("BAD ENDING", 100); std::cout << std::endl << std::endl;

        slowPrint("In the end, the player was arrested and executed in the kingdom of Uraya for mass murder.", 50); std::cout << std::endl << std::endl;
    }
}
