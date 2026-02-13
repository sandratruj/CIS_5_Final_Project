#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Haircare {
    string name;
    string hairTexture;
    string hairOiliness;
    string hairWorries;
};

void getHairDatainfo(Haircare &h);
void displayHairDatainfo(const Haircare &h);
void displayHairRecommendation(const Haircare &h, string* productPtr);
void printMenu();

int main(){
    string products[6] = {"Clarifying Shampoo", "Deep Conditioner", "Weightless Conditioner", 
      "Hair Mask", "Argan Oil", "Rosemary Oil"};

    Haircare h;
    char continueChoice;

    do {
        getHairDatainfo(h);
        displayHairDatainfo(h);
        displayHairRecommendation(h, products);
        cout << "\nWould you like start another round? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Have a great day!" << endl;
    return 0;
}

void getHairDatainfo(Haircare &h){
    cout<< "Welcome to the Haircare Recommendation System!" << endl;
    cout<< "Name: ";
    getline(cin, h.name);
int texChoice;
    do {
        cout << "\nSelect your hair texture:" << endl;
        cout << "1. Straight\n2. Wavy\n3. Curly\n4. Coily" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> texChoice;

        if (texChoice == 1) h.hairTexture = "Straight";
        else if (texChoice == 2) h.hairTexture = "Wavy";
        else if (texChoice == 3) h.hairTexture = "Curly";
        else if (texChoice == 4) h.hairTexture = "Coily";
        else cout << "Invalid. Please try again." << endl;

    } 
    while (texChoice < 1 || texChoice > 4);
    cout << "Is your hair oily? (y/n): ";
    char oily;
    cin >> oily;
    h.hairOiliness = (oily == 'y') ? "Oily" : "Dry";

    cout << "What are your hair worries? (frizz/breakage/dryness): ";
    cin >> h.hairWorries;
}

void displayHairDatainfo(const Haircare &h) {
    cout << "\nHair Profile for " << h.name << endl;
    cout << "Texture: " << h.hairTexture << endl;
    cout << "Type:    " << h.hairOiliness << endl;
    cout << "Worries: " << h.hairWorries << endl;
}

void displayHairRecommendation(const Haircare &h, string* productPtr) {
    cout << "Based on your " << h.hairTexture << " , " << h.hairOiliness << ", and, " << h.hairWorries<< " we recommend:" << endl;

    if (h.hairOiliness == "Oily" && h.hairWorries == "breakage") {
            cout << productPtr[0] << " and " << productPtr[1] << endl;
        } 
        else if (h.hairOiliness == "Dry" && h.hairWorries == "breakage") {
            cout << productPtr[5] << " and " << productPtr[3] << endl;
        } 
        else if (h.hairOiliness == "Oily" && h.hairWorries == "frizz") {
            cout << productPtr[0] << " and " << productPtr[4] << endl;
        } 
        else if ((h.hairTexture == "Straight" || h.hairTexture == "Wavy") && h.hairOiliness == "Dry" && h.hairWorries == "frizz"){
            cout << productPtr[1] << " and " << productPtr[5] << endl;
        }
        else if ((h.hairTexture == "Curly" || h.hairTexture == "Coily") && h.hairOiliness == "Dry" && h.hairWorries == "frizz") {
            cout << productPtr[1] << ", " << productPtr[4] << ", and " << productPtr[3] << endl;
        } 
        else if (h.hairOiliness == "Oily" && h.hairWorries == "dryness") {
            cout << productPtr[0] << " and " << productPtr[3] << endl;
        }
        else if (h.hairOiliness == "Dry" && h.hairWorries == "dryness") {
            cout << productPtr[4] << " and " << productPtr[1] << endl;
        }
    }