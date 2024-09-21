#include <iostream>
#include <fstream>
#include <string>

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
	cout << name << ": Hahaha, I like to play with you! :*" << endl;
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
        if (hygiene > 100) hygiene = 100;
        gainXP(5);
        cout << name << ": I feel so clean now! :)" << endl;
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
        cout << "Name: " << name << endl;
        cout << "Food: " << food << endl;
        cout << "Water: " << water << endl;
        cout << "Hygiene: " << hygiene << endl;
        cout << "Level: " << level << endl;
        cout << "XP: " << xp << endl;
    }

    void saveToFile() {
        ofstream file("mika.txt");
        file << name << endl;
        file << food << endl;
        file << water << endl;
        file << hygiene << endl;
        file << level << endl;
        file << xp << endl;
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
	    file.close();
        }
    }

    void menu() {
        int choice;
        while (true) {
	    saveToFile();
	    //cout << "Game saved!" << endl; //for debug

            cout << "\nWhat do you want to do?" << endl;
	    cout << "8. Play with " << name << endl;
            cout << "1. Feed" << endl;
            cout << "2. Give Water" << endl;
            cout << "3. Clean" << endl;
            cout << "4. Check Status of " << name << endl;
            cout << "5. Save" << endl;
            cout << "6. Load" << endl;
            cout << "7. Exit" << endl;
	    cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
		case 8:
		    play();
		    break;
                case 1:
                    feed();
                    break;
                case 2:
                    giveWater();
                    break;
                case 3:
                    clean();
                    break;
                case 4:
                    status();
                    break;
                case 5:
                    saveToFile();
                    cout << "Game saved!" << endl;
                    break;
                case 6:
                    loadFromFile();
                    cout << "Game loaded!" << endl;
                    break;
                case 7:
	    
	    cout << R"(
⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣄⡀⠀⢿⡿⣁⠀⢆⡘⠤⡘⠠⢰⠃⡄⠂⠄⠀⠀⠀⠀⡀⡆⠌⢄⠀⠀⢠⡇⠂⡌⠄⠀⠀⠀⠀⠀⠀⠡⣖⠀⢃⠸⠀⠸⣟⡄⠘⡽⡜⡄⠀⠀⠀⠈⠦⠀⠀⠀⠸
⣿⣿⣿⣿⣿⣿⡿⠁⠈⢻⡝⣟⣷⡿⢁⠤⢀⠢⢌⠰⡀⠂⡟⠠⡄⠈⠀⠀⣀⠤⠐⣰⠌⡈⢄⠂⡡⣺⠄⡇⠰⠈⡄⢃⠰⢀⠰⢀⠂⢽⠂⢼⠐⡠⠄⣿⡼⡀⠱⢹⡰⠀⠀⠀⠀⠀⣆⠀⠀⠀
⣿⣿⣿⣿⣿⣿⠁⢄⠠⢀⣹⣞⡿⢁⢊⠰⢀⠎⡐⢂⠁⢳⠋⠴⠁⠀⣠⠞⡠⢁⣺⡇⠤⢁⠢⠘⢠⡿⢰⡏⠄⢃⡐⢈⠰⢈⠰⢸⠌⣸⠌⢺⡐⠤⢈⣽⣧⢩⡄⢉⢧⠡⠉⡍⠒⠤⣸⡀⠀⠀
⣿⣿⣿⣿⣿⣿⠩⡐⠌⢿⡯⣿⠇⡌⠢⢡⠈⡔⠈⠂⠃⢾⢈⠒⠀⡴⢁⡾⠑⣸⢻⢀⠒⢠⠂⡉⢼⡇⢸⡇⠌⠄⡄⢃⠰⢈⠰⠸⡂⢼⢈⢹⠆⠰⢸⢿⠸⡆⢷⢈⠸⣄⠃⠤⢉⡐⠨⣧⠀⡀
⣿⣿⣿⣿⣿⣿⡟⣿⣻⢾⡷⣿⠐⡄⢃⠆⠈⠐⠁⠀⠀⣾⠸⠀⢀⡇⣼⠇⢡⡏⣇⠢⠘⡀⠆⢡⡎⡇⢺⣇⠘⢠⠐⠨⡐⢂⠢⢡⡇⠾⢈⢸⡃⡘⢼⢸⠀⢻⠈⣇⠌⣷⢈⡐⠂⠤⢱⢿⠀⠔
⣿⣿⣿⣿⣿⣿⣯⡚⢧⡻⣽⡏⠰⡈⢄⠈⠀⡀⠀⠀⠀⣿⢸⢀⢂⢸⡟⡈⢼⢳⠁⢂⡁⠆⡑⢺⢱⡇⣼⢿⠈⠄⡈⠡⢐⠠⢁⢺⡄⡟⡀⢺⢁⡴⡿⢸⢄⠈⡇⢺⡆⢸⡆⠤⢉⠰⢐⣸⠈⠔
⣿⣿⣿⣿⣿⣿⣿⣷⠁⢿⣹⡇⠡⠌⠀⠀⠀⠀⠀⠀⢀⡿⣸⠀⢂⣿⢃⠐⡞⡼⢈⣄⣐⣤⡴⡯⢼⠴⡿⢼⠾⠶⠶⠶⣤⠂⠌⣹⢰⡇⡐⡏⢸⢡⡇⡽⡀⠑⢳⠐⣷⠀⢿⡇⠌⡐⠂⡽⢈⡐
⣿⣿⣿⣿⣿⣿⣿⡏⠠⣄⣿⠄⠀⠀⠀⠀⠀⡅⠀⠠⢠⡟⣧⠈⣰⣿⠀⣼⠴⡗⢉⠉⡐⢠⢷⠃⢸⢠⠃⢸⣿⠀⢀⠂⢸⠀⢂⡏⣼⠁⣸⠁⡏⡜⡇⡧⠬⣴⣼⣀⢿⢇⢸⣹⠀⠀⡁⠇⡃⠄
⣿⣿⣿⣿⣿⣿⣿⣇⡷⠊⢸⠀⠀⠀⢠⣦⣄⠇⡈⢁⠆⣿⣧⠐⣽⡇⠐⣾⢰⡇⢂⠡⢈⡏⡞⠀⡼⣸⠀⠀⣿⠀⠀⠂⣏⠐⢸⢡⡟⢀⡏⣼⢱⠁⣧⠁⠀⠀⠈⡟⣻⠺⣤⣿⡆⠐⠀⡇⠄⡈
⣿⣿⣿⣿⣿⣿⣿⣿⣄⠂⣿⠀⠀⢠⠃⢿⣣⠐⠠⠌⠠⣿⣿⠀⢿⠃⢌⣿⠸⡇⢀⢂⡼⡼⠀⢀⢧⡯⠄⡀⣿⠀⠌⢰⡇⠈⣼⡿⠁⡞⣸⢇⠇⢰⡟⠀⠀⠀⠈⡇⡝⠀⢇⡟⡧⣄⠂⡇⠀⢰
⣿⣿⣿⣿⣿⡿⢭⢿⣿⣶⣻⡆⠀⡏⠠⠸⡽⣏⠐⡈⡐⢿⣻⡠⣿⠈⢸⡍⣆⣧⣾⣾⣿⣿⣶⣾⣾⣆⠄⠀⣿⡆⠀⣸⠁⣸⡿⢁⡞⡕⡹⡌⠀⣼⢁⠤⠤⢀⣀⡇⡇⠀⠸⣼⡇⠀⠑⣷⠈⣸
⣿⣿⣿⣿⣿⡹⢎⣗⡻⣿⣷⣇⠘⣇⠄⡁⢻⣽⡆⠡⠠⢹⣿⡓⣿⣴⣿⣿⣿⣿⡿⣟⣿⢫⣟⣏⠉⠙⠛⠶⣿⢿⠀⡞⢀⡟⢡⣾⠊⣰⠟⠀⣼⠃⣐⣤⣴⣦⣤⣧⣇⣠⠀⣿⡇⠀⡁⡏⠀⡿
⣿⣿⣿⡟⣧⣛⡭⢶⡙⣿⢻⣿⡄⢻⡔⠠⡈⢧⢿⡆⢡⠈⢿⣇⣷⣿⡿⠛⣯⢽⡳⢧⡞⠀⠀⣽⡀⠀⠀⠀⠛⠘⠻⢣⣞⣴⠟⠁⠠⠏⠀⠐⠁⢸⣿⢿⣟⠿⣿⡿⣿⣷⣤⣸⡂⠀⢸⠃⢰⠇
⣿⣿⡿⣹⣧⡓⢾⢷⡟⢸⣯⢹⣷⡌⢻⣄⠱⣌⠳⣿⣦⠲⠾⣿⣿⣿⠁⠈⣟⠊⢿⡧⢿⠃⡜⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣏⣟⡑⢀⡻⡴⢷⠈⠻⣿⣿⣟⠋⡟⢀⡎⠄
⣿⣿⠳⣽⠲⣝⡿⢸⡇⣸⠙⣷⢺⣿⣧⡻⣷⣌⢢⡙⢽⣷⣤⠘⢧⠙⢦⡀⢻⡌⠀⢠⢁⠒⢯⡀⠀⠀⠀⠀⠀⡀⠀⢀⠀⢀⠀⠀⠀⠀⠀⠀⠀⡏⣷⣹⡏⠵⡙⣺⠀⠀⠸⣿⣿⣾⢁⡾⠀⣲
⣿⢫⡝⣾⢹⣾⢃⢹⡇⢼⠂⣿⣹⠋⢉⡿⣾⣿⣷⣌⠲⣽⢿⣿⣮⣷⣀⠈⠀⠙⠗⠒⠚⡋⠉⠀⠀⠀⠀⣺⠂⠀⠀⢀⠀⠠⠐⣀⡀⠂⠀⠀⠀⢷⢈⠩⠀⡡⠲⠏⠀⠀⣸⢟⣽⣫⡟⢁⣴⢏
⣏⢷⣙⣮⠟⡐⠢⢼⡇⢸⡿⢧⣟⠀⡇⡄⣤⢩⢿⣛⢷⣤⣭⣛⢿⣮⠉⠳⠦⣤⠁⠁⡡⢈⢄⠡⠅⡆⠂⠀⠀⡈⠀⢈⡠⠆⠨⢀⠀⠀⠀⠄⠐⠈⠙⡲⢷⡼⡆⠀⠄⡐⠁⣿⣿⣋⣴⣾⢋⣾
⣞⢺⣼⠏⡐⠌⡁⣿⡇⢸⡇⠼⣿⠀⢷⠀⢹⡆⣿⡉⠚⠶⣭⣻⣿⡟⠢⢄⢤⢇⡀⡅⠦⠠⡴⠀⠀⠐⢐⠀⠆⠃⠄⠖⠉⠂⠅⠊⠁⢒⠄⠐⣀⠀⠂⠉⣀⠁⡄⠁⠈⠐⢸⣿⢫⣿⡳⣵⡿⢿
⣎⡿⢼⠂⡅⢊⠔⣿⣵⢺⡏⠄⣿⣧⡈⠓⢌⠷⢾⡇⢁⠢⢀⢹⠑⣷⠈⡠⠏⠤⠨⣁⢃⠕⠋⡫⢗⠉⠈⡂⠁⠀⢂⠐⢁⠣⠀⠁⠀⠘⠒⠥⠴⢄⢀⠐⠁⠀⠐⠀⠀⠈⡿⣬⡿⢣⡓⣸⣇⢻
⣾⣃⡯⢼⣀⠣⣈⣿⡽⣺⠛⢠⠹⡻⣿⣦⡀⠑⠪⣇⠂⠔⡈⡾⠊⣿⠎⠵⠃⡓⠀⡀⠉⠄⠆⠁⠉⠀⠈⠡⠂⠀⠀⡀⢈⣀⠊⣡⠂⠀⡐⠛⠊⢁⠰⠖⠃⠀⠁⢀⡀⢰⠟⡞⠡⢠⢰⣿⠸⣸
⣿⣿⣳⢯⣿⣿⣿⣷⣽⣹⡇⠌⣷⢳⢋⠻⢿⣦⣀⡟⡀⠊⢰⡇⠂⣿⡇⠠⠁⠀⠁⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⡔⠁⠀⠉⠢⢀⠀⠀⠀⠀⠈⠈⠁⢀⠠⠊⠀⠈⢺⡞⠠⢁⢂⣯⡏⠵⡘
⣿⣿⡜⣿⣿⣿⣿⣿⢾⣻⣧⡂⢹⣏⣿⡄⠌⢻⣿⣧⠀⠡⣸⠠⠁⣾⡇⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⢀⡠⠐⠁⠀⠀⠀⠀⠀⠀⠀⠉⠫⣦⠀⠀⢀⠔⠁⠀⠀⠀⡀⠀⠙⢦⢁⡞⣼⡙⢦⠑
⣿⣿⡽⣹⣿⣿⣿⣿⡯⣷⣯⢿⣄⠻⣜⣷⡈⠄⢻⣷⠈⢠⡗⠠⠁⣿⢸⣄⠀⠀⠀⠀⠀⠀⢀⡔⠊⠉⠀⠀⠀⠀⠀⠀⡰⠂⠤⣀⠀⠀⢀⣃⠀⣰⠁⠀⠀⡴⢴⣧⠀⡀⠀⠀⠙⢦⡏⡝⢢⠌
⡿⣿⣿⣽⣿⢿⣿⣿⡷⣣⢿⣯⣻⢷⣽⢞⣿⡄⠂⣿⠀⣸⠃⠠⢁⣷⠸⡇⠑⢤⡀⠀⣠⠞⠁⠀⠀⠀⠀⠀⠀⣀⠔⠀⠀⠀⠀⠈⢧⡀⢿⣿⣾⡿⠁⡠⢊⣴⣿⢸⡷⣄⣐⠀⢀⠄⠙⠓⠧⣌
⣿⣷⣿⣿⣿⣿⣿⣿⡿⣵⢫⣷⣏⣟⣾⣻⣾⣿⣆⢿⠀⡿⠀⠀⠂⣼⠐⣿⡀⢀⡼⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠒⢄⡀⠀⠀⠀⠀⠑⠮⠿⠛⠒⢈⣴⣿⣿⡏⡾⢁⠈⣿⠖⠁⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣳⣿⣿⣿⣯⣟⣷⢯⣿⣿⣿⢰⠃⠀⠀⠐⢸⠀⣻⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠲⠄⡀⠀⠀⠀⢀⣠⣾⣿⣿⣿⣿⣃⠇⢂⢡⠏⠀⠀⠀⠀⢀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣞⢾⡻⢷⣯⣿⣼⠀⠀⠀⢀⡼⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠲⣤⣀⡀⠀⠀⠀⠀⠈⠢⣤⣾⣿⣿⣿⣿⣿⣿⣿⢸⠠⡱⠃⠀⠀⠀⣠⣶⠋⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢾⣽⣯⣞⣽⡟⠀⣠⠔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣷⣤⡀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣷⣿⢀⡜⠁⠀⠀⣠⡞⡱⠁⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⢿⣿⣿⣿⣧⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠠⢀⠀⠀⠀⠀⠀⠀⠙⢿⣷⣄⡀⠀⠀⠀⠹⢿⣿⣿⣿⣿⡼⠀⠀⢀⣾⣿⡟⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡻⣞⢾⡹⡿⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠂⢄⡀⠀⠀⣠⣿⣿⣿⣿⣦⣄⠀⠀⠀⠻⣿⣿⡟⢀⠀⣡⠂⢺⣿⡣⢀⢀⠄⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣝⣾⣿⣧⢶⡶⣿⢿⣿⣦⣤⣀⣀⣀⣤⣀⣴⣶⣤⣤⣄⡀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⢠⣾⣿⣾⡷⣰⠉⡆⣹⣿⣿⣶⣿⣆⡀⢀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡞⣯⢷⣏⡿⣽⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣽⣿⡿⠕⠉⢆⢱⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡽⣾⣹⡞⣷⡽⣞⡽⣯⢿⣹⢯⣿⣿⣿⣿⣯⣿⡿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⢪⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⡽⣶⢯⡽⣞⣳⢯⡽⣞⣯⣽⢫⣿⡟⣿⣻⢿⡽⣿⣿⣿⣿⣻⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡈⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⢷⣛⡾⣽⣹⡽⢾⣹⠷⣞⣞⠿⣼⣿⡘⣯⣾⣿⢿⣹⢯⣟⡿⣿⢿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠈⠻⣿⣿⣿⣿⣿)";

                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            checkNeeds();
        }
    }

    void checkNeeds() {
        if (food < 50) {
            cout << name << ": I'm hungry!" << endl;
        }
        if (water < 50) {
            cout << name << ": I'm thirsty!" << endl;
        }
        if (hygiene < 50) {
            cout << name << ": I need a bath!" << endl;
        }
	if (happiness < 60) {
	    cout << name << ": Bu, I feel me sad. Do something with me!" << endl;
    	}
    }
};

int main() {
    Tamagotchi mika("Mika");
    mika.menu();
    return 0;
}
