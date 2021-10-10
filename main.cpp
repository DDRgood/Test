#include "train.h"
#include <algorithm>
#include <cctype>
#include <string>

const std::string quit = "q";
void toLowerStr(std::string& str)
{
    int i = 0;
    std::cout << "  LEN : " << str.length();
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i++]);
}


int main()
{
    Train* train = new Train();
    std::cout << *train;
    std::string choice = "";
    bool result = true;
    do
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Select action: " << std::endl;
        std::cout << "\t m - start move" << std::endl;
        std::cout << "\t s - stop move" << std::endl;
        std::cout << "\t o - open doors" << std::endl;
        std::cout << "\t c - close doors" << std::endl;
        std::cout << "\t p - print status" << std::endl;
        std::cout << "\t q - quit" << std::endl;
        std::cout << "input: ";
        std::cin >> choice;
        std::transform(choice.begin(), choice.end(), choice.begin(),
        [](unsigned char c){ return std::tolower(c); });
        //std::cout << std::endl;

        if (choice == "m")
            result = train->startMove();
        else if(choice == "s")
            result = train->stopMove();
        else if(choice == "o")
            result = train->openDoor();
        else if(choice == "c")
            result = train->closeDoor();
        else if(choice == "p")
            std::cout << *train;
        else if(choice == quit)
            std::cout << "Goodby!" << std::endl;
        else{
            std::cout << "Wrong choice, please try again" << std::endl;
            result = false;
        }
        
        if (result) std::cout << "\x1b[1;32m" << "done" << "\x1b[0m" << std::endl;
        else std::cout << "\x1b[1;31m" << "err" << "\x1b[0m" << std::endl;
        result = true;

    } while (choice != quit);
    
    delete train;

    return 0;
}