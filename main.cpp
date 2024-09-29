#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "wardrobe.h"

//Ideas: add energy for Mika, 

using namespace std;

class Tamagotchi {
private:
    string name;
    int food;
    int water;
    int hygiene;
    int level;
    int xp;
    int happiness;
    int money;
    string userName;
    int askMoneyDelay;
    int breakFromWork;

public:
    Tamagotchi(string name) {
        this->name = name;
        food = 100;
        water = 100;
        hygiene = 100;
        level = 1;
        xp = 0;
	happiness = 50;
	money = 0;
	userName = "User"; //set your name instead + + + + + + + + + + NOTICE IT PLEASE + + + + + + + + + +
	askMoneyDelay = 0;
	breakFromWork = 0;
    } //that's if you don't have a saved game
	
    void play() {
	happiness += 10;

	if (happiness > 100) {
		happiness = 100;
		cout << name << ": Phuh, I would like to take a break..." << endl;
		return;
	}

	srand(time(0));

	int randomNum = rand() % 3;

	if (randomNum == 0) {
		cout << name << ": Hahaha, I like to play with you! :*" << endl;
	}
	if (randomNum == 1) {
		cout << name << ": It was funny!" << endl;
	}
	if (randomNum == 2) {
	    	cout << name << ": Try to chase me ahaha!" << endl;
	}
    }

    void feed() {
	    if (money < 1) {
		    cout << "You don't have enough money to buy a food for " << name << ", try to work at first" << endl;
		    return;
	    }
        food += 10;
	money -= 1;
        if (food > 100) food = 100;
        gainXP(5);
        cout << name << ": Yum! That was delicious! :3" << endl;
    }

    void clrScr() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    }

    void giveWater() {
	   if (money < 1) {
		    cout << "You don't have enough money to buy a food for " << name << ", try to work at first" << endl;
		    return;
	    }

        water += 10;
	money -= 1;
        if (water > 100) water = 100;
        gainXP(5);
        cout << name << ": Ah, refreshing! Thank you so much! ^-^" << endl;
    }

    void clean() {
        hygiene += 10;
	happiness += 2;
        if (hygiene > 100) hygiene = 100;
        gainXP(5);
        cout << name << ": I feel so clean now! :)" << endl;
    }

    void patHead() {
	happiness += 10;
	gainXP(5);
	cout << name << ": Ahhh, I like it! :3" << endl;
    }

    void gainXP(int amount) {
        xp += amount;
        if (xp >= 100) {
            levelUp();
        }
    }

    void levelUp() {
        level++;
        xp = 0;
        cout << name << " leveled up! Now at level " << level << "!" << endl;
    }

    void status() {
        cout << "=== " << name << "'s info ===" << endl;
	cout << "--> Happiness: " << happiness << endl;
	cout << "--> Food: " << food << endl;
        cout << "--> Water: " << water << endl;
        cout << "--> Hygiene: " << hygiene << endl;
        cout << "--> Level: " << level << endl;
        cout << "--> XP: " << xp << endl;
	cout << "--> Money: " << money << endl;
    }

    void saveToFile() {
        ofstream file("mika.txt");
        file << name << endl;
        file << food << endl;
        file << water << endl;
        file << hygiene << endl;
        file << level << endl;
        file << xp << endl;
	file << happiness << endl;
	file << money << endl;
	file << askMoneyDelay;
	file << breakFromWork;
        file.close();
    }

    void loadFromFile() {
        ifstream file("mika.txt");
        if (file.is_open()) {
            file >> name;
            file >> food;
            file >> water;
            file >> hygiene;
            file >> level;
            file >> xp;
	    file >> happiness;
	    file >> money;
	    file >> askMoneyDelay;
	    file >> breakFromWork;
	    file.close();
        }
    }

    void userContinue() {
	    cout << "Press ENTER to continue..." << endl;
	    // FINISH IT... getchar
    }

    void visitClothesShop() {
	    cout << name << ": Wow! I see that soon this shop will have a lot of clothes which you will buy for me! :)" << endl;
    }

    void earnMoney() {
	    int earnMoneyChoice;
	    bool loop = true;

	    cout << "Choose a way to earn money:" << endl;
	    cout << "1. Work together with " << name << endl;
	    cout << "2. Ask " << name << "'s mother for money" << endl;
	    cout << "0. Go back" << endl;
	    
	    cin >> earnMoneyChoice;

	    switch(earnMoneyChoice) {
		    case 1:
			    if (breakFromWork > 20) {
				    
				    srand(time(0));
				    int randomNum = rand() % 3;
				    
				    if (randomNum == 0) {
					    cout << name << ": Nice, we worked in a bread store and earned 10 coins!*" << endl;
					    money += 10;
					    happiness += 5;
				    }
				    if (randomNum == 1) {
					    cout << name << ": We worked in a Red Cross and earned only 5 coins, but it was interesting!" << endl;
					    money += 5;
					    happiness += 10;
				    }
				    if (randomNum == 2) {
					    cout << name << ": Um, you worked as a miner and earned 20 coins. Pleasse, take a break!" << endl;
					    money += 20;
					    happiness -= 10;
				    }
			    

				    breakFromWork = 0;
			    	    return;
			    } else {
				    cout << name << ": I'm tired. Please, give me a break from work..." << endl;
				    cout << "(Steps: " << breakFromWork << "/20)" << endl;
				    return;
			    }
		    case 2:
			    if (askMoneyDelay > 100) {
				    cout << name << "'s mother: Okay, that's for you. These money only for my daughter!" << endl;
				    money += 20;
				    askMoneyDelay = 0;
				    return;
		   	    } else {
				    cout << name << "'s mother: Hey, I can't give you money too often!" << endl;
				    cout << "(Steps: " << askMoneyDelay << "/100)" << endl;
				    return;
			    }
		    case 0:
			    return;
		    default:
		    	cout << name << ": Um, can you repeat please? (Wrong choice)" << endl;
		    	return;
	    }
    }

    void openWardrobe() {
    Wardrobe myWardrobe;

    // Initialize wardrobe items
    strcpy(myWardrobe.hat, "None");
    strcpy(myWardrobe.accessories, "black sunglasses, pink backpack");
    strcpy(myWardrobe.clothes, "schoolgirl uniform");
    strcpy(myWardrobe.shoes, "None");

    int choice;
    do {
        printf("1. Hats\n");
        printf("2. Accessories\n");
        printf("3. Clothes\n");
        printf("4. Shoes\n");
        printf("5. Show chosen clothes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                break;
            case 5:
                showWardrobe(myWardrobe);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return;
}

    void showWardrobe(Wardrobe w) {
    	printf("== Chosen clothes ==\n");
    	printf("Hat: %s\n", w.hat);
    	printf("Accessories: %s\n", w.accessories);
    	printf("Clothes: %s\n", w.clothes);
    	printf("Shoes: %s\n\n", w.shoes);
    }

    void menu() {
        int choice;
	loadFromFile();
        while (true) {
	    srand(time(0));

	    int randomFood = rand() % 3;
	    int randomWater = rand() % 3;
	    int randomHygiene = rand() % 2;
	    int randomHappiness = rand() % 2;

	    food -= randomFood;
	    water -= randomWater;
	    hygiene -= randomWater;
	    happiness -= randomHappiness;

	    askMoneyDelay += 1;
	    breakFromWork += 1;

	    saveToFile();

	    status();

            cout << "\n\nWhat do you want to do?\n" << endl;
	    cout << "1. Play with " << name << endl;
            cout << "2. Feed" << endl;
            cout << "3. Give Water" << endl;
            cout << "4. Clean" << endl;
            cout << "5. Visit clothes shop together with " << name << endl;
	    cout << "6. Pat the head of " << name << endl;
	    cout << "7. Earn money" << endl;
	    cout << "8. Open wardrobe (SOON)" << endl;
            cout << "0. Exit\n" << endl;
	    cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
		case 0:
		    clrScr();
		    cout << "Bye, my boyfriend " << userName << "! :3" << endl;
                    return;
		case 1:
		    clrScr();
		    play();
		    break;
                case 2:
		    clrScr();
                    feed();
                    break;
                case 3:
		    clrScr();
                    giveWater();
                    break;
                case 4:
		    clrScr();
                    clean();
                    break;
                case 5:
		    clrScr();
                    visitClothesShop();
                    break;
		case 6:
		    clrScr();
		    patHead();
		    break;
		case 7:
		    clrScr();
		    earnMoney();
		    break;
		case 8:
		    clrScr();
		    openWardrobe();
		    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            checkNeeds();
        }
    }

    void checkNeeds() {
        if (food < 30) {
            cout << name << ": I'm hungry!" << endl;
        }
        if (water < 30) {
            cout << name << ": I'm thirsty!" << endl;
        }
        if (hygiene < 50) {
            cout << name << ": I need a bath!" << endl;
        }
	if (happiness < 20) {
	    cout << name << ": Bu, I feel me sad. Do something with me! :(" << endl;
    	}
	if (food < 0) food = 0;
	if (water < 0) water = 0;
	if (hygiene < 0) hygiene = 0;
	if (happiness < 0) happiness = 0;

	if (food > 100) food = 100;
	if (water > 100) water = 100;
	if (hygiene > 100) hygiene = 100;
	if (happiness > 100) happiness = 100;
    }
};

int main() {
    Tamagotchi mika("Mika");
    mika.menu();
    return 0;
}
