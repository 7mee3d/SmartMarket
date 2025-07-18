// SuperMark Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning ( disable : 4996 ) 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>


// Preproccessor Directive 

#define Integer  int 
using namespace std;

//Constants 
unsigned short int const kZERO{ 0 };
unsigned short int const kONE{ 1 };
unsigned short int const kNUMBER_TAB{ 2 };
unsigned short int const kNUMBER_LINE{ 1 };
unsigned short int const kNUMBER_SPACE_IN_ASCII{ 32 };

//Files Constant 
string const kFILE_NAME_PRODECTS_INFO = "Prodects.txt";
string const kFILE_NAME_PRODECTS_RECIEPT = "Reciept.txt";
string const kFILE_NAME_MANEGER_ADMIN = "Maneger_Supermarket.txt";


//enumration Supermarket 
enum enMainSuperMarket {

   kUSER = 1 , 
   kMANEGER = 2 ,
   kEXIT_SUPERMARKET =3 

};

enum enSectionUser {

    kSHOW_MENU = 1 , 
    kBUY_A_PRODUCT = 2 , 
    kRETURN_MAIN_MENU = 3 

};

enum enByAProductSecreen {

    kADD_A_PRODUCT = 1 , 
    kSHOW_THE_RECIEPT = 2 , 
    kCLEAR_ORDER  = 3 ,
    kRETURN_MAIN_MENU_BUY_PRODUCT_SECTION  = 4 

};

enum enSectionManeger  {

    kLOGIN_MANEGER = 1 , 
    kCREATE_NEW_EMAIL = 2 , 
    kRETURN_MAIN_MENU_MANEGER_   = 3 

};

enum enSectionManegerAfterLoginControlSupermarket  {

    kAdd_NEW_PRODUCT = 1,
    kEDIT_NAME_PRODUCT = 2,
    kEDIT_PRICE_PRODUCT = 3,
    kDELETE_PRODUCT = 4,
    kSHOW_ACCORDING_BY_USER = 5,
    kRETURN_MAIN_MENU_MANEGER  = 6

};
//end Enumrations 

//Storing information every product 

struct stInformationProdects {

    //Fileds
    unsigned short int ID{};
    string nameProdect{ "" };
    double priceProdect{};
    //Flags 

    bool makeDeleteProduct{ false }; 
};
struct stInformationManeger {

    //Fileds
   
    string username { "" };
    string password{ "" }; 


};

//end structure 

//Function Styling 
string FunctionCreateNewLine(unsigned short int const kNUMBER_HOW_MANY_LINE) {

    string newLine{ "" };
    int counter{ ::kONE };

    while (counter <= kNUMBER_HOW_MANY_LINE) {

        newLine += "\n";
        ++counter;

    }
    return newLine;
}

string FunctionPrintTabs(unsigned short Integer const kNUMBER_HOW_MANY_TABS) {

    string tabs{ "" };
    int counter{ ::kONE };

    while (counter <= kNUMBER_HOW_MANY_TABS) {

        tabs += "\t";
        ++counter;

    }
    return tabs;
}

void clearSecreenOnDetailes(void) {

    system("cls");

}

void ButtonPassReturnMainMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Main Menu .... ";
    system("pause>0");

}

void ButtonPassReturnSectionUserMenu (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Section User Menu .... ";
    system("pause>0");

}

void ButtonPassReturnSectionBuyProduct (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Section Buy Product Menu .... ";
    system("pause>0");

}

void ButtonPassReturnSectionManeger (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Section Maneger Menu .... ";
    system("pause>0");

}

void ButtonPassReturnSectionExit(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Section Exit Supermarket .... ";
    system("pause>0");

}
// end function styling 


//Start Function Headers 
void printHeaderWelcomeSuperMarketMainMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Welcome To Supermarket                   +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderUserSectionSuperMarket(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Welcome To User Section                  +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine( ::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderUserSectionSectionBuyProduct(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                  Welcome To Buy Product Section              +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE); 
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderUserSectionSectionShowReciept(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                  Welcome To Show The Seciept                 +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderExitSupermarket (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                          Exit Supermarket                    +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSection (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                    Welcome To Maneger Section                +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

} 
void printHeaderWelvomeManegerSectionLoginSecreen (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Welcome To Login Section                 +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSectionAddNewProductSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                Welcome To Add New Product Section            +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSectionEditNameProductSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+               Welcome To Edit Name Product Section           +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSectionEditPriceProductSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+              Welcome To Edit Price Product Section           +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}
void printHeaderWelvomeManegerSectionDeleteProductSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                 Welcome To Delete Product Section            +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSectionShowByUserSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+           Welcome to the How Does the User See screen        +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSectionCreateNewAccountSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                   Welcome to Create New Account              +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderWelvomeManegerSectionSureUserNameAndPassword (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+   Make sure your username and password are correct Secreen   +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}
void printHeaderUserSectionMainMenu(string const kNAME_USER) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                    Welcome , " << left << setw(32) << kNAME_USER << "+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                                                              +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      What You Can Make                       +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE );
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderManegerSectionMainMenu(string const &kNAME_MANEGER) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                    Welcome Back Sir, " << left << setw(24) << kNAME_MANEGER << "+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                                                              +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      What You Can Make                       +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}
//end  Function Headers 


//Start Function footer 
void footerShowProdect(void) {

    cout << "||                                                                                ||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||--------------------------------------------------------------------------------||" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE); 

}

void footerEverySecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";

}

void footerShowSecipt(double cost) {

    cout << "||                                        ||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||----------------------------------------||" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE); 
    cout << FunctionPrintTabs(::kNUMBER_TAB - ::kONE) << "     Total Cost : " << cost  << FunctionCreateNewLine(::kNUMBER_LINE);

}

//End  Function footer 


//Start  Function Menu 
void mainMenuOfSupermarket(void) {
  
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Do You want as a use ?                                  +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Do You want as a Maneger ?                              +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Exit Supermarket                                        +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
 
    footerEverySecreen();
}

void mainMenuOfUserSectionOfSuperMarket(void) {
   
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Show The Prodects                                       +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Buy a Prodact                                           +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- return a Main Menu                                      +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);

    footerEverySecreen();
}

void mainMenuOfUserSectionOfSuperMarketOfBuyProdect(void) {
   
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Add a product                                           +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Show The Reciept                                        +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Storing and Clear the last Orders                       +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- return a Section User                                   +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
  
    footerEverySecreen();
}

void mainMenuOfManegerSectionMainMenu (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Login Maneger                                           +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Create an Email                                         +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Return A Main Menu                                      +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);

    footerEverySecreen();
}


void mainMenuOfManegerAfterLoginSectionMainMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Add New Product                                         +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Edit Product Name                                       +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Edit Product Price                                      +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Delete Product                                          +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [5]- How a user sees the supermarket                         +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [6]- Return A Main Menu                                      +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|                                                                |" << FunctionCreateNewLine(::kNUMBER_LINE);

    footerEverySecreen();
}
//End Function Menu 


//Start Function Tabels 
void HeaderTabBarSectionUserShowProdects(unsigned long int numberProdects) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << FunctionPrintTabs(::kNUMBER_TAB + 1) << "Prodect list ( " << numberProdects << " ) Prodect(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << "||--------------------------------------------------------------------------------||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||    ID     |            Prodect Name                   |       Balance ($)      ||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||________________________________________________________________________________||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||                                                                                ||" << FunctionCreateNewLine((::kNUMBER_LINE));
}

void HeaderTabBarSectionUserShowReciept(unsigned long int numberProdects) {

    clearSecreenOnDetailes();

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << "        Prodect list ( " << numberProdects << " ) Prodect(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << "||----------------------------------------||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "|| ID |   Prodect Name   |   Balance ($)  ||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||________________________________________||" << FunctionCreateNewLine((::kNUMBER_LINE));
    cout << "||                                        ||" << FunctionCreateNewLine((::kNUMBER_LINE));
}

//End  Function Tabels 


//Function read ( number , text ) 

string readText(string const kMESSAGE) {

    string text{ "" };

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
    getline(cin >> ws, text);

    return text;
}

string readWord (string const kMESSAGE) {

    string text{ "" };

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
    cin >> text; 

    return text;
}

Integer readNumberPositiveInteger(const string kMESSAGE) {

    Integer number{::kZERO};

    do {

        cout << FunctionCreateNewLine (::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE ;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << kMESSAGE;
            cin >> number;
        }

    } while (number < ::kZERO);

    return number;
}

double readNumberPositiveFloatingPoint (const string kMESSAGE) {

    double number{ ::kZERO };

    do {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << kMESSAGE;
            cin >> number;
        }

    } while (number < ::kZERO);

    return number;
}
unsigned short Integer readNumberPositiveShortInteger(const string kMESSAGE) {

   unsigned short Integer number{ ::kZERO };

    do {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << kMESSAGE;
            cin >> number;
        }

    } while (number < ::kZERO);

    return number;
}

stInformationProdects readInformationProduct() {

    stInformationProdects informationProduct{};

    informationProduct.nameProdect = readText("Enter The Name Product : ");
    informationProduct.priceProdect = readNumberPositiveFloatingPoint("Enter The Price Product : ");

    return informationProduct; 
}

stInformationManeger readInformationManeger() {

    stInformationManeger informationManeger{};

    informationManeger.username = readWord("Enter The Username: ");
    informationManeger.password = readWord("Enter The Password : ");

    return informationManeger;
}


//Start Function string 

char toLowerCharacter(char const kCHARACTER) {

    return (kCHARACTER | ::kNUMBER_SPACE_IN_ASCII); 
}
vector<string> splitLine(string& line, string const kDELIMETER_SEPARATOR = ",||,") {

    vector<string> split{};
    Integer positionEveryWord{};
    string newWord{ "" };


    while ((positionEveryWord = line.find(kDELIMETER_SEPARATOR)) != string::npos) {

        newWord = line.substr(::kZERO, positionEveryWord);

        if (newWord != "")
            split.push_back(newWord);


        line.erase(::kZERO, positionEveryWord + kDELIMETER_SEPARATOR.length());
    }

    if (!line.empty())
        split.push_back(line);

    return split;
}

stInformationProdects convertLineToRecordProdect(vector<string> const& kLINES) {

    stInformationProdects infoProdect{};

    if (kLINES.size() < 3) {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "Warning: Invalid product line detected (less than 3 fields)."
            << FunctionCreateNewLine(::kNUMBER_LINE);

        return infoProdect;
    }

    try {
        infoProdect.ID = stoi(kLINES[0]);
        infoProdect.nameProdect = kLINES[1];
        infoProdect.priceProdect = stod(kLINES[2]);
    }
    catch (...) {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
             << FunctionPrintTabs(::kNUMBER_TAB)
             << "Error: Failed to parse product data!"
             << FunctionCreateNewLine(::kNUMBER_LINE);

    }

    return infoProdect;
}

stInformationManeger convertLineToRecordManegerInformation (vector<string> const& kLINES) {

    stInformationManeger infoManeger{};

    if (kLINES.size() < 2) {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "Warning: Invalid product line detected (less than 3 fields)."
            << FunctionCreateNewLine(::kNUMBER_LINE);

        return infoManeger;
    }

    try {
        infoManeger.username = kLINES[::kZERO];
        infoManeger.password = kLINES[::kONE];
    }
    catch (...) {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "Error: Failed to parse product data!"
            << FunctionCreateNewLine(::kNUMBER_LINE);

    }

    return infoManeger;
}



string convertRecordToLine_Reciept(stInformationProdects informationProductRecipt, string const& kDELIMETER = ",||,"  ) {

    string line{ "" };

    line += to_string ( informationProductRecipt.ID  ) +  kDELIMETER;
    line += informationProductRecipt.nameProdect + kDELIMETER;
    line += to_string( informationProductRecipt.priceProdect ) ;
    line += FunctionCreateNewLine(::kNUMBER_LINE); 


    return line; 
}

string convertRecordToLine(stInformationProdects informationProduct, string const& kDELIMETER = ",||,") {

    string line{ "" };

    line += to_string(informationProduct.ID) + kDELIMETER;
    line += informationProduct.nameProdect + kDELIMETER;
    line += to_string(informationProduct.priceProdect);

    return line;
}

string convertRecordToLine_Maneger(stInformationManeger informationManeger, string const& kDELIMETER = "**//**") {

    string line{ "" };

    line += informationManeger.username + kDELIMETER;
    line += informationManeger.password ;


    return line;
}

double calcTotalCostRecept(vector<stInformationProdects> & InformationRecieptProduct) {

    double cost{  ::kZERO };
    for (stInformationProdects& info : InformationRecieptProduct)
        cost += info.priceProdect;

    return cost;


}

//Print Reciept in the File 

string getSystemDate() {

    time_t timee = time(NULL);

    tm* timeLocal = localtime(&timee); 

    string time = to_string(timeLocal->tm_mday) + "/" + to_string(timeLocal->tm_mon + kONE) + to_string(timeLocal->tm_year + 1900); 

    return time; 
}
void loadLineToFileReciept(string const kFILE_NAME , vector<stInformationProdects>&  kINFORMATION_PRODECT) {

    fstream file; 
    file.open(kFILE_NAME, ios::out | ios::app );

    if (file.is_open()) {

        string line{ "" }; 
        file << FunctionCreateNewLine(::kNUMBER_LINE) << "-------------------------------------" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
        file << "           Reciept  " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE  ); 
        file << "      Date Reciept :  " << getSystemDate() <<  FunctionCreateNewLine(::kNUMBER_LINE  );
        file << FunctionCreateNewLine(::kNUMBER_LINE ) << "-------------------------------------" << FunctionCreateNewLine(::kNUMBER_LINE + ::kNUMBER_LINE);

        for (stInformationProdects const& kInfo : kINFORMATION_PRODECT) {

            line = convertRecordToLine_Reciept(kInfo ,",||,"  );

            file << line << FunctionCreateNewLine(::kNUMBER_LINE ) ;
        }
        file << FunctionCreateNewLine(::kNUMBER_LINE) <<  "Total Cost of Reciept = " << calcTotalCostRecept(kINFORMATION_PRODECT) << FunctionCreateNewLine(::kNUMBER_LINE );
        file << FunctionCreateNewLine(::kNUMBER_LINE) << "-------------------------------------" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
      
       
    } 
    file.close();
}

void loadLineToFile(string const kFILE_NAME, vector<stInformationProdects>& kINFORMATION_PRODECT , string const kDELIMETER = ",||,") {

    fstream file;
    file.open(kFILE_NAME, ios::out );

    if (file.is_open()) {

        string line{ "" };

        for (stInformationProdects const& kInfo : kINFORMATION_PRODECT) {
            if (kInfo.makeDeleteProduct == false) {
                line = convertRecordToLine(kInfo, ",||,");
                file << line << endl;
            }
        }


    }
    file.close();
}

void loadLineToFile(string const &kFILE_NAME, vector<stInformationManeger> &kINFORMATION_MANEGER, string const kDELIMETER = "**//**") {

    fstream file;
    file.open(kFILE_NAME, ios::out);

    if (file.is_open()) {

        string line{ "" };

        for (stInformationManeger const& kINFO_MANEGER : kINFORMATION_MANEGER) {
       
                line = convertRecordToLine_Maneger(kINFO_MANEGER, "**//**");
                file << line << endl;
            
        }

        file.close();

    }
}

vector<stInformationProdects> loadLineFromFileProdects(string const& kFILE_NAME, string const& kDELIMETER = ",||,") {
   
    vector<stInformationProdects> informationProdect;
    vector<string> wordSplits;

    fstream file;
    file.open(kFILE_NAME, ios::in);

    if (file.is_open()) {

        string line{ "" };
        stInformationProdects infoProdect{};
       

        while (getline(file, line)) {

            wordSplits = splitLine(line, kDELIMETER);
            infoProdect = convertLineToRecordProdect(wordSplits);
            informationProdect.push_back(infoProdect);

        }
        file.close();
    }

    return informationProdect;
}



vector<stInformationManeger> loadLineFromFileInformationManeger(string const kFILE_NAME, string const& kDELIMETER = "**//**") {

    vector<stInformationManeger> informationManeger;
    vector<string> wordSplits;

    fstream file;
    file.open(kFILE_NAME, ios::in);

    if (file.is_open()) {

        string line{ "" };
        stInformationManeger infoManeger{};


        while (getline(file, line)) {

            wordSplits = splitLine(line, kDELIMETER);
            infoManeger = convertLineToRecordManegerInformation(wordSplits);
            informationManeger.push_back(infoManeger);

        }
        file.close();
    }

    return informationManeger;
}

//End  Function string 

//Start Function Print One product   
void printInformationEveryProdect(stInformationProdects const& kINFORMATION_PRODECT) {

        cout << "|| " << left << setw(10) << kINFORMATION_PRODECT.ID  << "| ",
        cout << left << setw(42) << kINFORMATION_PRODECT.nameProdect  << "| ",
        cout << left << setw(23) << kINFORMATION_PRODECT.priceProdect << "||";
        cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printInformationShowReciept(stInformationProdects const& kINFORMATION_PRODECT) {

        cout << "|| " << left << setw(3) << kINFORMATION_PRODECT.ID   <<    "| ",
        cout << left << setw(17) << kINFORMATION_PRODECT.nameProdect  <<    "| ",
        cout << left << setw(13) << kINFORMATION_PRODECT.priceProdect <<  "  ||";
        cout << FunctionCreateNewLine(::kNUMBER_LINE);

}
//End Function Print One product  
// 

//Start Function of Sections 

void FunctionShowMenuProdect(string const& kFILE_NAME, string const& kDELIMETER = ",||,") {
   
    vector<stInformationProdects> const kINFORMATION_PRODECTS = loadLineFromFileProdects(kFILE_NAME, kDELIMETER);
    long int numberOfProdects = kINFORMATION_PRODECTS.size();

    HeaderTabBarSectionUserShowProdects(numberOfProdects);

    for (stInformationProdects const& infoProdect : kINFORMATION_PRODECTS) {

        printInformationEveryProdect(infoProdect);
    }

    footerShowProdect();
}

bool isFoundIDProduct(int idProduct , vector<stInformationProdects> const& kINFORMATION_PRODECT, stInformationProdects& infoProductOne) {
  
    for (const stInformationProdects& infoProduct : kINFORMATION_PRODECT) {

        if (idProduct == infoProduct.ID) {

            infoProductOne = infoProduct;
            return false;
            break;

        }
    }

    return true;
}

void readIdProductToOrder( vector<int> &numberProduct, vector<stInformationProdects> const& kINFORMATION_PRODECT_SECTION_BUY  , stInformationProdects info) {
   
    char Choise = 'Y';

    while (Choise == 'Y' || Choise == 'y') {

        bool flagIsFound = true;
        int number{ ::kZERO } ;

        do {

            number = readNumberPositiveInteger("Enter the ID Product to adding the order : ");
            flagIsFound = isFoundIDProduct(number, kINFORMATION_PRODECT_SECTION_BUY, info);

            if (flagIsFound) {
                cout << FunctionCreateNewLine(::kNUMBER_LINE)
                     << FunctionPrintTabs(::kNUMBER_TAB)
                     << "Alert !!! This ID is not found in the Menu ..."
                     << FunctionCreateNewLine(::kNUMBER_LINE) ;
            }

        } while (flagIsFound);

        numberProduct.push_back(number);
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
            << "Do You Want to Add More Products? [Y/N] ?? ";
        cin >> Choise;
    }
}

void FunctionShowReciept(vector<int>& numbersProduct, vector<stInformationProdects>& InformationRecieptProduct  ,  vector<stInformationProdects> const& kINFORMATION_PRODECT) {

    HeaderTabBarSectionUserShowReciept(numbersProduct.size());

    if (numbersProduct.size() > ::kZERO) {

        for (int counter{ ::kZERO }; counter < numbersProduct.size(); counter++) {
            stInformationProdects infoProduct;

            if (isFoundIDProduct(numbersProduct[counter], kINFORMATION_PRODECT, infoProduct) == false) {

                printInformationShowReciept(infoProduct);
                InformationRecieptProduct.push_back(infoProduct);

            }
        }
    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "   Empty" << FunctionCreateNewLine(::kNUMBER_LINE);
    }
    footerShowSecipt(calcTotalCostRecept (InformationRecieptProduct));
}


void exitSupermarket(void) {

    clearSecreenOnDetailes();
    printHeaderExitSupermarket();
    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Thanks for using my supermarket. See you later. (: ";

    ButtonPassReturnSectionExit();
    exit(0);
}


bool isFoundUsername(string const  kUSERNAME , vector<stInformationManeger>& kINFORMATION_MANEGER  ) {

    for (int counter{ 0 }; counter < kINFORMATION_MANEGER[0].username.size(); counter++) {
        if (kUSERNAME[counter] != kINFORMATION_MANEGER[0].username[counter]) {
            return false; 
            break; 
        }
  }
    return true;
}
bool isFoundPasswordAndUsername(string const& kUSERNAME, string const& kPASSWORD, vector<stInformationManeger>& kINFORMATION_MANEGER) {
    for (auto& informationManeger : kINFORMATION_MANEGER) {
        if ((informationManeger.username == kUSERNAME) && (informationManeger.password == kPASSWORD)) {
            return true;
        }
    }
    return false;
}

bool isFoundIdProductToSectionManeger(unsigned short Integer const& kID_PRODUCT, vector<stInformationProdects> const  kINFORMATION_PRODUCT) {

    for (stInformationProdects const &kINFO_PRODUCT : kINFORMATION_PRODUCT) {
        if (kID_PRODUCT == kINFO_PRODUCT.ID) {
            return true; 
            break;
        }
    }
    return false; 
}

void FunctionAddNewProduct(string const& kFILE_NAME) {

    vector<stInformationProdects>  kINFORMATION_PRODUCT = loadLineFromFileProdects(kFILE_NAME ,",||,");
    stInformationProdects infoProduct; 

   const unsigned short Integer ID_PRODUCT = readNumberPositiveInteger("Enter The Id  : ");

    if (!isFoundIdProductToSectionManeger(ID_PRODUCT ,  kINFORMATION_PRODUCT)) {

       
        //Read Information Product 
        infoProduct = readInformationProduct(); 
        infoProduct.ID = ID_PRODUCT;
        kINFORMATION_PRODUCT.push_back(infoProduct);
        loadLineToFile(::kFILE_NAME_PRODECTS_INFO, kINFORMATION_PRODUCT);
        cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) <<
            FunctionPrintTabs(::kNUMBER_TAB) << "- Product is Add In Product " <<FunctionCreateNewLine(::kNUMBER_LINE) ;
        ButtonPassReturnSectionManeger();
       
    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << 
            FunctionPrintTabs(::kNUMBER_TAB) << 
            "This ID ( " << ID_PRODUCT << " ) Already Exits , Please Sir Try Again (:"
            << FunctionCreateNewLine(::kNUMBER_LINE); 

        ButtonPassReturnSectionManeger();
    }

    
}

bool  FunctionManegerLogin(string const& kFILENAME , string& nameManeger ) {

    vector<stInformationManeger> kINFORMATION_MANEGER = loadLineFromFileInformationManeger(::kFILE_NAME_MANEGER_ADMIN, "**//**");

    string username { "" } ;
    string password{ "" };

    Integer Choise{ ::kZERO };
    Integer counter{ ::kZERO } ;

    do {
        username = readText("Enter Username: ");
        password = readText("Enter Password: ");

        bool flag = false;

        flag = isFoundPasswordAndUsername(username, password, kINFORMATION_MANEGER);

        if (flag) {

                printHeaderManegerSectionMainMenu(username);
                mainMenuOfManegerAfterLoginSectionMainMenu();
                nameManeger = username;

                counter = ::kZERO;
                    return true; 
                      break;


    } else {

            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Invalid username or password! , Please Try Agian \n";
            counter++; 
        }
        

    } while (counter <= 2); // 2--> Number of attempts to reach 2

    return false; 

}


void printInformationOneProduct(stInformationProdects infoProduct) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + ::kONE) << "- ID Product    : " << infoProduct.ID << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + ::kONE) << "- Name Product  : " << infoProduct.nameProdect << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + ::kONE) << "- Price Product : " << infoProduct.priceProdect << FunctionCreateNewLine(::kNUMBER_LINE);
}

void editedProductName(string const kNAME_NEW_PRODUCT, unsigned short Integer const kID_PRODUCT ,   vector<stInformationProdects> & kINFORMATION_PRODUCT , stInformationProdects &infoProduct  ) {

    for (stInformationProdects& infoP : kINFORMATION_PRODUCT) {
        if (infoP.ID == kID_PRODUCT) {
            infoP.nameProdect = kNAME_NEW_PRODUCT;
            infoProduct = infoP; 
        }
    }
}

void editedProductPrice( double const kPRICE_PRODUCT  , unsigned short Integer const kID_PRODUCT, vector<stInformationProdects>& kINFORMATION_PRODUCT, stInformationProdects& infoProduct) {

    for (stInformationProdects& infoP : kINFORMATION_PRODUCT) {
        if (infoP.ID == kID_PRODUCT) {
            infoP.priceProdect = kPRICE_PRODUCT;
            infoProduct = infoP;
        }
    }
}
void FunctionEditNameProduct(string const kFILE_NAME) {

    char Choise{ 'N' };

    vector<stInformationProdects> kINFORMATION_PRODUCT = loadLineFromFileProdects(::kFILE_NAME_PRODECTS_INFO); 
    const unsigned short Integer  ID_PRODUCT = readNumberPositiveInteger("Enter The Id  : "); 

    stInformationProdects infoProduct; 

    if (!(isFoundIDProduct(ID_PRODUCT, kINFORMATION_PRODUCT, infoProduct))) {
       
        footerEverySecreen();
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "This Following Details Product Id ( " << ID_PRODUCT << " ) " << FunctionCreateNewLine(::kNUMBER_LINE);
        printInformationOneProduct(infoProduct);
        footerEverySecreen();

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Are you Sure Edit Name This Product .. [Y/N] ? ";
        cin >> Choise;

            if (toLowerCharacter (Choise) == 'y') {

                string const kNEW_NAME_PRODUCT = readText("Enter The New Name Of Product : ");
                editedProductName(kNEW_NAME_PRODUCT, ID_PRODUCT, kINFORMATION_PRODUCT, infoProduct);
                cout << FunctionCreateNewLine(::kNUMBER_LINE);
             
                cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Product After Edited Name : " << FunctionCreateNewLine(::kNUMBER_LINE);
                printInformationOneProduct(infoProduct); 
                footerEverySecreen();

            }

            loadLineToFile( ::kFILE_NAME_PRODECTS_INFO , kINFORMATION_PRODUCT , ",||,");

    }

    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) 
             << FunctionPrintTabs(::kNUMBER_TAB)
             << "This ID Product ( " << ID_PRODUCT 
             <<" ) Not Found ): " <<FunctionCreateNewLine(::kNUMBER_LINE) ;

    }

}


void FunctionEditPriceProduct(string const kFILE_NAME) {

    char Choise = 'N';

    vector<stInformationProdects> kINFORMATION_PRODUCT = loadLineFromFileProdects(::kFILE_NAME_PRODECTS_INFO);
    const unsigned short  Integer ID_PRODUCT = readNumberPositiveInteger("Enter The Id  : ");
    stInformationProdects infoProduct;


    if (!(isFoundIDProduct(ID_PRODUCT, kINFORMATION_PRODUCT, infoProduct))) {

        footerEverySecreen();
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "This Following Details Product Id ( " << ID_PRODUCT << " ) " << FunctionCreateNewLine(::kNUMBER_LINE);
        printInformationOneProduct(infoProduct);
        footerEverySecreen();

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Are you Sure Edit Price This Product .. [Y/N] ? ";
        cin >> Choise;

        if (toLowerCharacter(Choise) == 'y') {

            double const kNEW_PRICE = readNumberPositiveFloatingPoint("Enter The New Price Of Product : ");

            editedProductPrice(kNEW_PRICE, ID_PRODUCT, kINFORMATION_PRODUCT, infoProduct);
            cout << FunctionCreateNewLine(::kNUMBER_LINE);

            cout << FunctionCreateNewLine(::kNUMBER_LINE) 
                 << FunctionPrintTabs(::kNUMBER_TAB)
                 << "The Product After Edited Price : " 
                 << FunctionCreateNewLine(::kNUMBER_LINE);

            printInformationOneProduct(infoProduct);
            footerEverySecreen();

        }

        loadLineToFile(::kFILE_NAME_PRODECTS_INFO, kINFORMATION_PRODUCT, ",||,");

    }

    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) 
             << FunctionPrintTabs(::kNUMBER_TAB)
             << "This ID Product ( " << ID_PRODUCT 
             << " ) Not Found ): " 
             << FunctionCreateNewLine(::kNUMBER_LINE);

    }

}

bool makeFlagTrueToDeleteThisProduct( unsigned short int  const kID_PRODUCT, vector<stInformationProdects>& kINFORMATION_PRODUCT, stInformationProdects& infoProduct) {
   
    for (stInformationProdects& infoP : kINFORMATION_PRODUCT) {

        if (infoP.ID == kID_PRODUCT) {

            infoP.makeDeleteProduct = true; 
            infoProduct = infoP;
            break;

        }
    }
    return false; 

}


void FunctionDeleteProduct(string const kFILE_NAME) {

    char Choise = 'N';

    vector<stInformationProdects> kINFORMATION_PRODUCT = loadLineFromFileProdects(::kFILE_NAME_PRODECTS_INFO);

    const unsigned short Integer ID_PRODUCT = readNumberPositiveInteger("Enter The Id  : ");

    stInformationProdects infoProduct;

    if (!(isFoundIDProduct(ID_PRODUCT, kINFORMATION_PRODUCT, infoProduct))) {

        footerEverySecreen();
        cout << FunctionCreateNewLine(::kNUMBER_LINE) 
             << FunctionPrintTabs(::kNUMBER_TAB)
             << "This Following Details Product Id ( "
             << ID_PRODUCT << " ) "
             << FunctionCreateNewLine(::kNUMBER_LINE);

        printInformationOneProduct(infoProduct);
        footerEverySecreen();

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Are you Sure Delete This Product .. [Y/N] ? ";
        cin >> Choise;

        if (toLowerCharacter(Choise) == 'y') {

            makeFlagTrueToDeleteThisProduct( ID_PRODUCT, kINFORMATION_PRODUCT, infoProduct);

            cout << FunctionCreateNewLine(::kNUMBER_LINE);
            cout << FunctionPrintTabs(::kNUMBER_TAB) << "This Product is Delete (: " << FunctionCreateNewLine(::kNUMBER_LINE);

            loadLineToFile(::kFILE_NAME_PRODECTS_INFO, kINFORMATION_PRODUCT, ",||,");

            footerEverySecreen();


        }

    }

    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
             << FunctionPrintTabs(::kNUMBER_TAB) 
             << "This ID Product ( " << ID_PRODUCT
             << " ) Not Found ): " 
             << FunctionCreateNewLine(::kNUMBER_LINE);

    }

}

void FunctionCreateNewAccount(string const kFILE_NAME) {

    vector<stInformationManeger> infoManeger = loadLineFromFileInformationManeger(kFILE_NAME , "**//**");
    stInformationManeger infoNewManeger; 

    infoNewManeger = readInformationManeger();
    infoManeger.push_back(infoNewManeger);

    //Load Vector to file 
    loadLineToFile(::kFILE_NAME_MANEGER_ADMIN, infoManeger, "**//**");


}

//End Function of Sections 



// Start Function Supermarket 

void secreenWelcomeOfSectionBuy_Products(void) {

    clearSecreenOnDetailes();
    printHeaderUserSectionSectionBuyProduct();
    mainMenuOfUserSectionOfSuperMarketOfBuyProdect();


}

void secreenWelcomeSupermarketSectionManeger(void) {

    clearSecreenOnDetailes();
    printHeaderWelvomeManegerSection();
    mainMenuOfManegerSectionMainMenu();

}

void FunctionBuyProduct(string const& kFILE_NAME) {

    int Choise{ ::kZERO } ;
    vector<stInformationProdects> const kINFORMATION_PRODECT = loadLineFromFileProdects(::kFILE_NAME_PRODECTS_INFO);

     stInformationProdects product ;
     vector<int> numberProduct;
     vector<stInformationProdects> vectorTemp ;

    while (true) {

        secreenWelcomeOfSectionBuy_Products();

        Choise = readNumberPositiveInteger("Enter Choise According The Menu  : ");

        enByAProductSecreen choiseEnumration = static_cast <enByAProductSecreen> (Choise);

        switch (choiseEnumration) {

        case enByAProductSecreen::kADD_A_PRODUCT :
            FunctionShowMenuProdect(::kFILE_NAME_PRODECTS_INFO);
            printHeaderUserSectionSectionBuyProduct();
            readIdProductToOrder(numberProduct, kINFORMATION_PRODECT, product);
           
            ButtonPassReturnSectionBuyProduct();
         
            break;

        case enByAProductSecreen::kSHOW_THE_RECIEPT :

            FunctionShowReciept(numberProduct, vectorTemp,  kINFORMATION_PRODECT);
            ButtonPassReturnSectionBuyProduct();

            break;

        case enByAProductSecreen::kCLEAR_ORDER:

            loadLineToFileReciept(::kFILE_NAME_PRODECTS_RECIEPT, vectorTemp);
            vectorTemp.clear();
            numberProduct.clear(); 

            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
                << "Order cleared. Ready for a new order." << FunctionCreateNewLine(::kNUMBER_LINE);
            ButtonPassReturnSectionBuyProduct();

            break;

        case enByAProductSecreen::kRETURN_MAIN_MENU_BUY_PRODUCT_SECTION:
            return;
            break; 

        default:
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) <<
                FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
        }
    }
}

void FunctionUser() {

    Integer Choise{ ::kZERO } ;
    string name{ "" } ;

    clearSecreenOnDetailes();
    printHeaderUserSectionSuperMarket();

    name = readText("Please , Enter the name in pairs : ");

    while (true) {

        printHeaderUserSectionMainMenu(name);
        mainMenuOfUserSectionOfSuperMarket();

        Choise = readNumberPositiveInteger("Enter Choise According The Menu  : ");

        enSectionUser choiseEnumration = static_cast <enSectionUser> (Choise);

        switch (choiseEnumration) {

        case enSectionUser::kSHOW_MENU :

            FunctionShowMenuProdect(::kFILE_NAME_PRODECTS_INFO);
            ButtonPassReturnSectionUserMenu();

            break;

        case enSectionUser::kBUY_A_PRODUCT :

            FunctionBuyProduct(::kFILE_NAME_PRODECTS_INFO);

            break;

        case enSectionUser::kRETURN_MAIN_MENU :
            return;
            break;

        default:
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE ) <<
                FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
        }
       
        clearSecreenOnDetailes();
        printHeaderUserSectionSuperMarket();
    }
}

void sectionManegerAfterLogin (string const& kNAME_MANEGER ) {

    while (true) {

        clearSecreenOnDetailes();
        printHeaderManegerSectionMainMenu(kNAME_MANEGER);

        mainMenuOfManegerAfterLoginSectionMainMenu();

        Integer managerChoice = readNumberPositiveInteger("Enter Manager Choice: ");
        enSectionManegerAfterLoginControlSupermarket choiseEnumrationManeger = static_cast <enSectionManegerAfterLoginControlSupermarket> (managerChoice);

        switch (choiseEnumrationManeger) {

        case enSectionManegerAfterLoginControlSupermarket::kAdd_NEW_PRODUCT :
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionAddNewProductSecreen();
            FunctionAddNewProduct(::kFILE_NAME_PRODECTS_INFO);

            break;

        case enSectionManegerAfterLoginControlSupermarket::kEDIT_NAME_PRODUCT :
            clearSecreenOnDetailes(); 
            printHeaderWelvomeManegerSectionEditNameProductSecreen();
            FunctionEditNameProduct(::kFILE_NAME_PRODECTS_INFO);
            ButtonPassReturnSectionManeger();
            break;

        case enSectionManegerAfterLoginControlSupermarket::kEDIT_PRICE_PRODUCT :
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionEditPriceProductSecreen();
            FunctionEditPriceProduct(::kFILE_NAME_PRODECTS_INFO);
            ButtonPassReturnSectionManeger();
            break; 

        case enSectionManegerAfterLoginControlSupermarket::kDELETE_PRODUCT :
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionDeleteProductSecreen();
            FunctionDeleteProduct(::kFILE_NAME_PRODECTS_INFO);
            ButtonPassReturnSectionManeger();
            break;

        case enSectionManegerAfterLoginControlSupermarket::kSHOW_ACCORDING_BY_USER :
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionShowByUserSecreen();
            FunctionUser();
            ButtonPassReturnSectionManeger();
            break;

        case enSectionManegerAfterLoginControlSupermarket::kRETURN_MAIN_MENU_MANEGER :

            return; 
            break;

        default:

            cout << FunctionCreateNewLine(::kNUMBER_LINE )
                 << FunctionPrintTabs(::kNUMBER_TAB)
                 << "Invalid choice! , Try Agian Sir " 
                 << FunctionCreateNewLine(::kNUMBER_LINE  ) ;
        }
    }
}


void sectionManeger(string const kFILE_NAME) {

    Integer Choise{ ::kZERO } ;
    string nameManeger{ "" }; 

    while (true) {

        secreenWelcomeSupermarketSectionManeger();
        Choise = readNumberPositiveInteger("Enter Choice: ");

        switch (Choise) {

        case enSectionManeger::kLOGIN_MANEGER :
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionLoginSecreen();
            if (FunctionManegerLogin(kFILE_NAME , nameManeger )) {
                sectionManegerAfterLogin(nameManeger);
            
            }
            break; 
        case enSectionManeger::kCREATE_NEW_EMAIL  :
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionCreateNewAccountSecreen();
            FunctionCreateNewAccount(::kFILE_NAME_MANEGER_ADMIN);
            // New Function 
            clearSecreenOnDetailes();
            printHeaderWelvomeManegerSectionSureUserNameAndPassword();
            if (FunctionManegerLogin(kFILE_NAME, nameManeger)) {

                sectionManegerAfterLogin(nameManeger);

            }
            break; 

        case enSectionManeger::kRETURN_MAIN_MENU_MANEGER_:
            
            return; 
            break; 
        }
      
        }
       
    
}
void secreenWelcomeSupermarket(void) {

    clearSecreenOnDetailes();
    printHeaderWelcomeSuperMarketMainMenu();
    mainMenuOfSupermarket();

}


void Supermarket (void) {

    Integer Choise{ ::kZERO } ;

    while (true) {

        secreenWelcomeSupermarket();
      
        Choise = readNumberPositiveInteger("Enter Choise According The Menu  : " ); 

        enMainSuperMarket choiseEnumration = static_cast <enMainSuperMarket> (Choise);

        switch (choiseEnumration) {

        case enMainSuperMarket::kUSER  :
            FunctionUser();
            break;

        case enMainSuperMarket::kMANEGER :
            sectionManeger(::kFILE_NAME_MANEGER_ADMIN); 
          
            ButtonPassReturnMainMenu();
            break; 

        case enMainSuperMarket::kEXIT_SUPERMARKET : 
            exitSupermarket();

        default:
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) <<
                FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
        }
    }
}



// End  Function Supermarket 
int main() {

    Supermarket();
}
