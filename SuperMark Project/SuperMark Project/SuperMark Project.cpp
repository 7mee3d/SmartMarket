// SuperMark Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Constants 
unsigned short int const kZERO{ 0 };
unsigned short int const kONE{ 1 };
unsigned short int const kNUMBER_TAB{ 2 };
unsigned short int const kNUMBER_LINE{ 1 };

//Files Constant 
string const kFILE_NAME_PRODECTS_INFO = "Prodects.txt";
string const kFILE_NAME_PRODECTS_RECIEPT = "Reciept.txt";


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
//end Enumrations 

//Storing information every product 
struct stInformationProdects {

    //Fileds
    unsigned short int ID{};
    string nameProdect{ "" };
    double priceProdect{};

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

string FunctionPrintTabs(unsigned short int const kNUMBER_HOW_MANY_TABS) {

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
// end function styling 

//Start Function Headers 
void printHeaderWelcomeSuperMarketMainMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                       Welcome To Supermarket                 +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printHeaderUserSectionSuperMarket(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      Welcome To User Section                 +|" << FunctionCreateNewLine(::kNUMBER_LINE);
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
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                   Welcome To Show The Seciept                +|" << FunctionCreateNewLine(::kNUMBER_LINE);
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

void printHeaderUserSectionMainMenu(string const kNAME_USER) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                    Welcome , " << left << setw(32) << kNAME_USER << "+|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                                                              +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      What You Can Make                       +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE );
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
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- User                                                    +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Maneger                                                 +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Exit                                                    +|" << FunctionCreateNewLine(::kNUMBER_LINE);
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
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Clear Current Order                                     +|" << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- return a Section User                                   +|" << FunctionCreateNewLine(::kNUMBER_LINE);
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

int readNumberPositiveInteger(const string kMESSAGE) {

    int number{::kZERO};

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


//Start Function string 
vector<string> splitLine(string& line, string const kDELIMETER_SEPARATOR = ",||,") {

    vector<string> split{};
    int positionEveryWord{};
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

string convertRecordToLine_Reciept(stInformationProdects informationProductRecipt, string const& kDELIMETER = ",||,"  ) {

    string line{ "" };

    line += to_string ( informationProductRecipt.ID  ) +  kDELIMETER;
    line += informationProductRecipt.nameProdect + kDELIMETER;
    line += to_string( informationProductRecipt.priceProdect ) ;
    line += FunctionCreateNewLine(::kNUMBER_LINE); 


    return line; 
}

double calcTotalCostRecept(vector<stInformationProdects> & InformationRecieptProduct) {

    double cost{  ::kZERO };
    for (stInformationProdects& info : InformationRecieptProduct)
        cost += info.priceProdect;

    return cost;


}
void loadLineToFile(string const kFILE_NAME , vector<stInformationProdects>&  kINFORMATION_PRODECT) {

    fstream file; 
    file.open(kFILE_NAME, ios::out | ios::app );

    if (file.is_open()) {

        string line{ "" }; 
        file << FunctionCreateNewLine(::kNUMBER_LINE) << "-------------------------------------" << FunctionCreateNewLine(::kNUMBER_LINE);
        file << "        Reciept : " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE ); 
        for (stInformationProdects const& kInfo : kINFORMATION_PRODECT) {

            line = convertRecordToLine_Reciept(kInfo ,",||,"  );

            file << line << endl;
        }
        file << "Total Cost of Reciept = " << calcTotalCostRecept(kINFORMATION_PRODECT) << FunctionCreateNewLine(::kNUMBER_LINE );
        file << FunctionCreateNewLine(::kNUMBER_LINE) << "-------------------------------------" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
      
       
    } 
    file.close();
}

vector<stInformationProdects> loadLineFromFileProdects(string const kFILE_NAME, string const& kDELIMETER = ",||,") {
   
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

bool isFoundIDProduct(int& idProduct , vector<stInformationProdects> const& kINFORMATION_PRODECT, stInformationProdects& infoProductOne) {
  
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
    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Thank you using Supermarket sir ";

    ButtonPassReturnMainMenu();
    exit(0);
}
//End Function of Sections 



// Start Function Supermarket 
void secreenWelcomeOfSectionBuy_Products(void) {

    clearSecreenOnDetailes();
    printHeaderUserSectionSectionBuyProduct();
    mainMenuOfUserSectionOfSuperMarketOfBuyProdect();


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

            loadLineToFile(::kFILE_NAME_PRODECTS_RECIEPT, vectorTemp);
            vectorTemp.clear();
            numberProduct.clear(); 

            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
                << "Order cleared. Ready for a new order." << FunctionCreateNewLine(::kNUMBER_LINE);
            ButtonPassReturnSectionBuyProduct();

            break;

        case 4:
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

    int Choise{ ::kZERO } ;
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



void secreenWelcomeSupermarket(void) {

    clearSecreenOnDetailes();
    printHeaderWelcomeSuperMarketMainMenu();
    mainMenuOfSupermarket();

}


void Supermarket (void) {

    int Choise{ ::kZERO } ;

    while (true) {

        secreenWelcomeSupermarket();
      
        Choise = readNumberPositiveInteger("Enter Choise According The Menu  : " ); 

        enMainSuperMarket choiseEnumration = static_cast <enMainSuperMarket> (Choise);

        switch (choiseEnumration) {

        case enMainSuperMarket::kUSER  :
            FunctionUser();
            break;

        case enMainSuperMarket::kMANEGER :
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