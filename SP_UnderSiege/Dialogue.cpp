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
    slowPrint("You play as Rueben. As a child, your village was destroyed by raiders.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Being the only one alive, you trained and gathered intel for many years to track down and kill the mercenaries who destroyed your village.", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("Fast forward to present times, your intel has located the leader that lead the group of raiders.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Residing in the kingdom of URAYA, the mercenary known as Raif has now become the King's hired mercenary,", 10); Sleep(500); std::cout << std::endl;
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

    slowPrint("RUEBEN: How do I get permission? I need to speak to one of the general that goes by the name Raif urgently.", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("GUARD: Hmm", 10); slowPrint(".....", 500); slowPrint("Talk to our superior for access, I think I saw him near the south of the city.", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::MeetSuperiorFirstTime()
{
    slowPrint("RUEBEN: Hey! I need to talk to yo-", 10); Sleep(1000); std::cout << std::endl << std::endl;

    slowPrint("SUPERIOR: Hm? Who are you?", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("RUEBEN: So you are alive", 10); slowPrint(".....", 500); slowPrint("You are Raif's partner, Bryan, I remember you.", 30); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("(You pull out your weapon, preparing to fight.)", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::BeatSuperiorFirstTime()
{
    slowPrint("BRYAN: Arghh!", 50); Sleep(1000); slowPrint(" I-I remember you now, why are you doing this?!", 50); std::cout << std::endl << std::endl;

    slowPrint("RUEBEN: ", 10); slowPrint(".....", 500); Sleep(1000); slowPrint("One down, one to go.", 50); Sleep(1000); std::cout << std::endl << std::endl;

    slowPrint("(It's time to find Raif at the Castle.)", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::MeetBoss()
{
    slowPrint("RAIF: You..... Its you! You're alive! What.....What have you done!?", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("RUEBEN: I finally found you after all these years, I also had to pay your friend a little visit.", 10); std::cout << std::endl << std::endl;

    system("pause");
}

void Dialogue::DefeatBoss()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    slowPrint("(Raif falls to the ground beneath you, struggling in pain.)", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("RAIF: After what we did", 30); slowPrint(".....", 500); slowPrint("This is how you repay us?", 30); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("RUEBEN: What do you mean, you destroyed the village!", 10); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("RAIF: No! It was the Goblin's who did it! We tried to saved the village from the Goblin's attack, but we could not win.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Before escaping, I found a baby in his dead parents arms, and I took him away to a orphanage.", 10); Sleep(500); std::cout << std::endl;
    slowPrint("Please", 100); slowPrint(".....", 500); slowPrint("You don't need to do this.", 50); Sleep(2000); std::cout << std::endl;

    std::cout << "Spare Him. (A) or Kill him. (B) " << std::endl;
    do
    {
        std::cin >> choice;

        if (choice == 'A')
        {
            slowPrint("RUEBEN: I'm sorry", 30); slowPrint(".....", 500); slowPrint("I-I didn't know. I killed so many.....", 50); std::cout << std::endl << std::endl;

            slowPrint("RAIF: The deed is done", 50); slowPrint(".....", 500); slowPrint("The dead cannot come back. Run away now kid.", 10); Sleep(2000); std::cout << std::endl << std::endl;

            SetConsoleTextAttribute(h, 0x02);
            slowPrint("GOOD ENDING", 200); Sleep(2000); std::cout << std::endl << std::endl;
            SetConsoleTextAttribute(h, 0x0f);

            slowPrint("In the end, the Rueben runs away from the kingdom and started his new life as a farmer.", 30); std::cout << std::endl << std::endl;
        }
        else if (choice == 'B')
        {
            slowPrint("Rueben kills Raif, avenging his dead family. Not knowing the full truth", 30); slowPrint(".....", 500); std::cout << std::endl << std::endl;

            slowPrint("As Raif draws his last breath, Rueben breaks down crying, for the revenge that he long yearned for", 30); std::cout << std::endl;
            slowPrint("did not grant him peace.", 50); Sleep(2000); std::cout << std::endl;

            SetConsoleTextAttribute(h, 0x04);
            slowPrint("BAD ENDING", 200); Sleep(2000); std::cout << std::endl << std::endl;
            SetConsoleTextAttribute(h, 0x0f);

            slowPrint("In the end, Rueben was arrested and executed in the kingdom of Uraya for mass murder.", 50); std::cout << std::endl << std::endl;
        }
    } while (choice != 'A' && choice != 'B');
}

void Dialogue::Dead()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    slowPrint("RUEBEN: Argghhh!!", 50); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("Ruben drops his sword and falls onto the ground.", 50); Sleep(500); std::cout << std::endl << std::endl;

    slowPrint("For Rueben's life", 50); slowPrint(".....", 500); slowPrint("It started with death and ended with it.", 50);Sleep(500); std::cout << std::endl << std::endl;

    SetConsoleTextAttribute(h, 0x04);
    slowPrint("BAD ENDING", 200); Sleep(2000); std::cout << std::endl << std::endl;
    SetConsoleTextAttribute(h, 0x0f);
}
