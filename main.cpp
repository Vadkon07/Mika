#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

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

public:
    Tamagotchi(string name) {
        this->name = name;
        food = 100;
        water = 100;
        hygiene = 100;
        level = 1;
        xp = 0;
	happiness = 50;
    }
	
    void play() {
	happiness += 10;

	if (happiness > 100) {
		happiness = 100;
		cout << ": Phuh, I would like to take a break..." << endl;
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
        food += 10;
        if (food > 100) food = 100;
        gainXP(5);
        cout << name << ": Yum! That was delicious! :3" << endl;
    }

    void giveWater() {
        water += 10;
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
	cout << "Happiness: " << happiness << endl;
	cout << "Food: " << food << endl;
        cout << "Water: " << water << endl;
        cout << "Hygiene: " << hygiene << endl;
        cout << "Level: " << level << endl;
        cout << "XP: " << xp << endl;
	cout << "Money: SOON" << endl;
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
	    file.close();
        }
    }

    void menu() {
        int choice;
	loadFromFile();
        while (true) {
	    srand(time(0));

	    int randomFood = rand() % 5;
	    int randomWater = rand() % 5;
	    int randomHygiene = rand() % 4;
	    int randomHappiness = rand() % 2;

	    food -= randomFood;
	    water -= randomWater;
	    hygiene -= randomWater;
	    happiness -= randomHappiness;

	    saveToFile();

            cout << "\nWhat do you want to do?" << endl;
	    cout << "1. Play with " << name << endl;
            cout << "2. Feed" << endl;
            cout << "3. Give Water" << endl;
            cout << "4. Clean" << endl;
            cout << "5. Check Status of " << name << endl;
	    cout << "6. Pat the head of" << name << endl;
            cout << "0. Exit" << endl;
	    cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
		case 0:
		    cout << "Bye my boy! :3" << endl;
                    return;
		case 1:
		    play();
		    break;
                case 2:
                    feed();
                    break;
                case 3:
                    giveWater();
                    break;
                case 4:
                    clean();
                    break;
                case 5:
                    status();
                    break;
		case 6:
		    patHead();
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
    }
};

int main() {
    Tamagotchi mika("Mika");
    mika.menu();
    return 0;
}
