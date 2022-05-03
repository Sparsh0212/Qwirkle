#include "Menu.h"
#include "Colors.h"

enum class Page {
    MainPage,
    NewGamePage,
    ExitPage,
    CreditPage,
    LoadGamePage,
};

Menu::Menu()
{
    /*Start the game.*/
    std::cout << "Welcome to QWIRKLE!" << std::endl;
    std::cout << "-------------------\n" << std::endl;
    PageControl();
}

Menu::~Menu() {
}

int Menu::ShowMainPage()
{
    /*Shows the main menu, and return the *valid* user input.*/

    int choice = -1;

    while (choice < 1 || choice > 4) {
        
        if (choice != -1) std::cout << "Invalid Input. Please Try Again.\n" << std::endl;
        
        if (!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout << "Menu" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << ">";
        std::cin >> choice;
        
   }
    
    return choice;
}

void Menu::ShowCreditPage()
{
    setTextColor(BLUE_TXT);
   std::cout << "---------------------------------------------" << std::endl;
   std::cout << "Name: Aiden Perona" << std::endl;
   std::cout << "Student ID: s3539619" << std::endl;
   std::cout << "Email Address: s3539619@student.rmit.edu.au" << std::endl;
   std::cout << " " << std::endl;
   std::cout << "Name: Deshan Adihetty" << std::endl;
   std::cout << "Student ID: s3854348" << std::endl;
   std::cout << "Email Address: s3854348@student.rmit.edu.au" << std::endl;
   std::cout << " " << std::endl;
   std::cout << "Name: Edmund Boon Qing Tan" << std::endl;
   std::cout << "Student ID: s3698291" << std::endl;
   std::cout << "Email Address: s3698291@student.rmit.edu.au" << std::endl;
   std::cout << " " << std::endl;
   std::cout << "Name: Sparsh Gupta" << std::endl;
   std::cout << "Student ID: s3810922" << std::endl;
   std::cout << "Email Address: s3810922@student.rmit.edu.au" << std::endl;
   std::cout << "---------------------------------------------\n\n" << std::endl;
   resetTextColor(RESET_COLOR);
}

void Menu::PageControl()
{
    /*Main Page Loop. Will be called by the constructor.*/
    /*Shows the suitable page to user, e.g. main page, credit...*/

    Page page{ Page::MainPage };

    while (true) {

        if (page == Page::MainPage) {

            int selection = this->ShowMainPage();
            if (selection == 4) page = Page::ExitPage;
            else if (selection == 3) page = Page::CreditPage;
            else if (selection == 2) page = Page::LoadGamePage;
            else if (selection == 1) page = Page::NewGamePage;

            /*change the page value based on selection.*/
        }
        else if (page == Page::NewGamePage) {
            this->game.InitializeUI();
            this->game.StartGameloop();
            //page = Page::MainPage;
        }
        else if (page == Page::LoadGamePage) {
            // Take user input, create a fstream as fin and pass to loadgame
            std::cout << "Enter the filename" << std::endl;
            std::string fName;
            std::cin >> fName;
            std::string cur_ply = this->game.LoadGame(fName);
            this->game.StartGameloop(cur_ply);
            
        }
        else if (page == Page::CreditPage) {

            this->ShowCreditPage();

            /*Back to main page.*/
            page = Page::MainPage;
        }
        else if (page == Page::ExitPage) {
            
             std::cout << "Goodbye " << std::endl;
            return;
        }

    }
}
