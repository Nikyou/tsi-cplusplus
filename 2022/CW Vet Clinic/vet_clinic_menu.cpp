#include "vet_clinic_menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for sort
#include <cstring>


void StringBounder(std::string& str, unsigned int i) {
    auto n = str.length();
    if (i < n) {
        n = i;
    }
    std::vector<char> strv(str.begin(), str.begin() + static_cast<__int64>(n));
    str.clear();
    for (char c : strv) {
        str.push_back(c);
    }
}

void Clear() //https://stackoverflow.com/questions/6486289/how-can-i-clear-console/52895729#52895729
{
    std::cout << "\n\n\n\n\n";  //if none of the below OS used
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void AnyKeyReturn(int& outputsize) {
    std::string text = "Enter any key to return";
    Outputconverter(text, outputsize);
    std::cout << text;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

time_t InputDate() {
    unsigned int i;
    tm date = { 0 };
    do {
        std::cout << "Day: ";
        std::cin >> i;
        if ((std::cin.fail()) or (i > 31) or (i == 0)) {
            std::cin.clear();
            std::cout << "invalid input, try again\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            date.tm_mday = static_cast<int>(i);
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Month: ";
        std::cin >> i;
        if ((std::cin.fail()) or (i > 12) or (i == 0)) {
            std::cin.clear();
            std::cout << "invalid input, try again\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            date.tm_mon = static_cast<int>(i) - 1;
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Year: ";
        std::cin >> i;
        if ((std::cin.fail()) or (i < 1970)) {	//clear input if it was bad
            std::cin.clear();
            std::cout << "invalid input, try again\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            date.tm_year = static_cast<int>(i) - 1900;
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Hour: ";
        std::cin >> i;
        if ((std::cin.fail()) or (i > 23)) {	//clear input if it was bad
            std::cin.clear();
            std::cout << "invalid input, try again\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            date.tm_hour = static_cast<int>(i);
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Minutes: ";
        std::cin >> i;
        if ((std::cin.fail()) or (i > 59)) {	//clear input if it was bad
            std::cin.clear();
            std::cout << "invalid input, try again\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            date.tm_min = static_cast<int>(i);
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return mktime(&date);
}

void FilesInitialise(std::vector<Species>& spec,
 std::string& specfile, std::vector<Characteristics>& charac,
 std::string& characfile, std::vector<Gender>& gen, std::string& genfile,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Reason>& reason, std::string& reasonfile,
 std::vector<Appointment>& app, std::string& appfile) {

    ReadSpecies(spec, specfile);
    ReadCharacteristics(charac, characfile);
    ReadGender(gen, genfile);
    ReadAnimal(animal, animalfile);
    ReadOwner(owner, ownerfile);
    ReadReason(reason, reasonfile);
    ReadAppointment(app, appfile);
}

std::string bool_to_string(const bool b) {  //converts bool to true/false string
    if (b) {
        return "true";
    }
    else {
        return "false";
    }
}

void MenuDataSortingText(int& outputsize, const short int choice,
 const std::vector<unsigned short int> prio,
 const std::vector<std::string> sign) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2: //handling any owner case
        text = "Set sorting priority and type.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner ID";
        if (prio[0] != 0) {
            text = text + ": " + std::to_string(prio[0]) + " " + sign[0]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Full Name";
        if (prio[1] != 0) {
            text = text + ": " + std::to_string(prio[1]) + " " + sign[1]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Number of Animals";
        if (prio[2] != 0) {
            text = text + ": " + std::to_string(prio[2]) + " " + sign[2]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Reset sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sort\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;

    case 3: //handling any animal case
        text = "Set sorting priority and type.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal ID";
        if (prio[0] != 0) {
            text = text + ": " + std::to_string(prio[0]) + " " + sign[0]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Name";
        if (prio[1] != 0) {
            text = text + ": " + std::to_string(prio[1]) + " " + sign[1]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Specie";
        if (prio[2] != 0) {
            text = text + ": " + std::to_string(prio[2]) + " " + sign[2]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Breed";
        if (prio[3] != 0) {
            text = text + ": " + std::to_string(prio[3]) + " " + sign[3]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Gender";
        if (prio[4] != 0) {
            text = text + ": " + std::to_string(prio[4]) + " " + sign[4]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Years of Age";
        if (prio[5] != 0) {
            text = text + ": " + std::to_string(prio[5]) + " " + sign[5]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Weight";
        if (prio[6] != 0) {
            text = text + ": " + std::to_string(prio[6]) + " " + sign[6]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Owner ID";
        if (prio[7] != 0) {
            text = text + ": " + std::to_string(prio[7]) + " " + sign[7]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "9: Reset sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "10: Sort\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "11: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4: //handling any appointment case
        text = "Set sorting priority and type.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Appointment ID";
        if (prio[0] != 0) {
            text = text + ": " + std::to_string(prio[0]) + " " + sign[0]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner ID";
        if (prio[2] != 0) {
            text = text + ": " + std::to_string(prio[2]) + " " + sign[2]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Animal ID";
        if (prio[3] != 0) {
            text = text + ": " + std::to_string(prio[3]) + " " + sign[3]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Date";
        if (prio[4] != 0) {
            text = text + ": " + std::to_string(prio[4]) + " " + sign[4]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Reason";
        if (prio[5] != 0) {
            text = text + ": " + std::to_string(prio[5]) + " " + sign[5]
                + "\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Reset sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Sort\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 7:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuDataSorting(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<unsigned short int> prio,
 std::vector<std::string> sign) {

    short int choice;
    unsigned short int priority;
    MenuDataSortingText(outputsize, oldchoice, prio, sign);
    switch (oldchoice) {
    case 1:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSorting(outputsize, 2, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                Clear();
                MenuDataSorting(outputsize, 3, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                Clear();
                MenuDataSorting(outputsize, 4, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 2:
        priority = 1;
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0){
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 4:
                std::sort(owner.begin(), owner.end(), CompareOwnerbyidasc);
                prio = std::vector<unsigned short int>(8, 0);
                sign = std::vector<std::string>(8, "dec");
                priority = 1;
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                std::cout << "\nReseted\n";
                break;
            case 5:
                SortOwner(owner, prio, sign);
                std::cout << "Done\n";
                break;
            case 6:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 6);
        break;
    case 3:
        priority = 1;
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 4:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 5:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 6:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 7:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 8:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 9:
                std::sort(animal.begin(), animal.end(), CompareAnimalbyidasc);
                prio = std::vector<unsigned short int>(8, 0);
                sign = std::vector<std::string>(8, "dec");
                priority = 1;
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                std::cout << "\nReseted\n";;
                break;
            case 10:
                SortAnimal(animal, prio, sign);
                std::cout << "Done\n";
                break;
            case 11:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 11);
        break;
    case 4:
        priority = 1;
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 4:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 5:
                if (prio[static_cast<unsigned __int64>(choice) - 1] == 0) {
                    prio[static_cast<unsigned __int64>(choice) - 1] = priority;
                    priority++;
                }
                if (sign[static_cast<unsigned __int64>(choice) - 1] == "dec") {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "asc";
                }
                else {
                    sign[static_cast<unsigned __int64>(choice) - 1] = "dec";
                }
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 6:
                std::sort(app.begin(), app.end(), CompareAppointmentbyidasc);
                prio = std::vector<unsigned short int> (8, 0);
                sign = std::vector<std::string> (8, "dec");
                priority = 1;
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                std::cout << "\nReseted\n";
                break;
            case 7:
                SortAppointment(app, prio, sign);
                std::cout << "Done\n";
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
        break;
    case 5:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSorting(outputsize, 2, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                Clear();
                MenuDataSorting(outputsize, 3, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 6:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSorting(outputsize, 3, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                Clear();
                MenuDataSorting(outputsize, 4, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 7:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSorting(outputsize, 3, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 2:
                Clear();
                MenuDataSorting(outputsize, 4, animal, owner, app, prio, sign);
                Clear();
                MenuDataSortingText(outputsize, oldchoice, prio, sign);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    }
}

void MenuDataFiltersNextText(int& outputsize, const short int choice,
 const unsigned short int selected) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Choose sign.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: < (less than)";
        if (selected == 1) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: <= (less than or equal to)";
        if (selected == 2) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: = (equal to)";
        if (selected == 3) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: != (not equal to)";
        if (selected == 4) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: >= (greater than or equal to)";
        if (selected == 5) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: > (greater than)";
        if (selected == 6) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Value\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2:
        text = "Choose sign.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: = (equal to)";
        if (selected == 3) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: != (not equal to)";
        if (selected == 4) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Value\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 3: //any unsigned int case
        text = "Write a positive natural number.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4: //any float case
        text = "Write a positive real number.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5: //any object string case
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the main menu\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6: //any date case
        text = "Write date and time in the folowing format: Day.Month.Year "
            "Hour:Minute. Year cannot be less than 1900.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuDataFiltersNext(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason, const unsigned short int object,
  const unsigned short int data, unsigned short int selected) {
    //object: 1 - owner  2 - animal  3 - appointment
    //data: respective data to object starting from 1

    unsigned short int choice;
    std::string text;
    unsigned int intvalue1;
    unsigned int intvalue2;
    std::string strvalue1;
    std::string strvalue2;
    float floatvalue;
    time_t timevalue;
    tm date = { 0 };
    std::vector<std::string> sign(7, "");

    if (!(oldchoice == 5)) {
        MenuDataFiltersNextText(outputsize, oldchoice, 0);
    }
    switch (oldchoice) {
    case 1:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                selected = choice;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 2:
                selected = choice;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 3:
                selected = choice;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 4:
                selected = choice;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 5:
                selected = choice;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 6:
                selected = choice;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 7:
                if (selected != 0) {
                    Clear();
                    if (((object == 1) and (data == 2)) or ((object == 2) and
                        (data == 5))) {
                        MenuDataFiltersNext(outputsize, 3, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    if ((object == 2) and (data == 6)) {
                        MenuDataFiltersNext(outputsize, 4, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    if ((object == 3) and (data == 4)) {
                        MenuDataFiltersNext(outputsize, 6, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    Clear();
                    MenuDataFiltersNextText(outputsize, oldchoice, selected);
                }
                else {
                    text = "Choose a sign\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                }
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
        break;
    case 2:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                selected = 3;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 2:
                selected = 4;
                Clear();
                MenuDataFiltersNextText(outputsize, oldchoice, selected);
                break;
            case 3:
                if (selected) {
                    Clear();
                    if (((object == 2) and (data == 2)) or ((object == 2) and
                        (data == 3)) or ((object == 2) and (data == 4)) or
                        ((object == 3) and (data == 5))) {
                        MenuDataFiltersNext(outputsize, 5, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    if (((object == 1) and (data == 1)) or ((object == 2) and
                        (data == 1)) or ((object == 2) and (data == 7)) or
                        ((object == 3) and (data == 1)) or ((object == 3) and
                            (data == 2)) or ((object == 3) and (data == 3))) {
                        MenuDataFiltersNext(outputsize, 3, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    Clear();
                    MenuDataFiltersNextText(outputsize, oldchoice, selected);
                }
                else {
                    text = "Choose a sign\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                }
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 3:
        do {
            std::cout << "Enter: ";
            std::cin >> intvalue1;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cout << "invalid input, try again\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                break;
            }

        } while (true);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if ((object == 1) and (data == 1)) {
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            owner = FilterOwner(owner, sign, intvalue1, intvalue2);
        }

        if ((object == 1) and (data == 2)) {
            if (selected == 1) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            owner = FilterOwner(owner, sign, intvalue2, intvalue1);
        }
        if ((object == 2) and (data == 1)) {
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            animal = FilterAnimal(animal, sign, intvalue1, strvalue2,
                strvalue2, strvalue2, intvalue2, floatvalue, intvalue2);

        }
        if ((object == 2) and (data == 5)) {
            if (selected == 1) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            animal = FilterAnimal(animal, sign, intvalue2, strvalue2,
                strvalue2, strvalue2, intvalue1, floatvalue, intvalue2);
        }
        if ((object == 2) and (data == 7)) {
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            animal = FilterAnimal(animal, sign, intvalue2, strvalue2,
                strvalue2, strvalue2, intvalue2, floatvalue, intvalue1);

        }
        if ((object == 3) and (data == 1)) {
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            app = FilterAppointment(app, sign, intvalue1, intvalue2, intvalue2,
                timevalue, strvalue1);
        }
        if ((object == 3) and (data == 2)) {
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            app = FilterAppointment(app, sign, intvalue2, intvalue1, intvalue2,
                timevalue, strvalue1);
        }
        if ((object == 3) and (data == 3)) {
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            app = FilterAppointment(app, sign, intvalue2, intvalue2, intvalue1,
                timevalue, strvalue1);
        }
        break;
    case 4:
        do {
            std::cout << "Enter: ";
            std::cin >> floatvalue;
            if ((std::cin.fail()) or (floatvalue <= 0)) {
                std::cin.clear();
                std::cout << "invalid input, try again\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (!(floatvalue) or (floatvalue <= 0));

        if ((object == 2) and (data == 6)) {
            if (selected == 1) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            animal = FilterAnimal(animal, sign, intvalue2, strvalue2,
                strvalue2, strvalue2, intvalue2, floatvalue, intvalue2);
        }
        break;
    case 5:
        choice = 0;
        if ((object == 2) and (data == 2)) {
            TableOutputSpecies(spec, outputsize);
            choice = static_cast<unsigned short int>(spec.size() - 1);
        }
        if ((object == 2) and (data == 3)) {
            TableOutputCharacteristics(charac, outputsize);
            choice = static_cast<unsigned short int>(charac.size() - 1) ;
        }
        if ((object == 2) and (data == 4)) {
            TableOutputGender(gen, outputsize);
            choice = static_cast<unsigned short int>(gen.size() - 1) ;
        }
        if ((object == 3) and (data == 5)) {
            TableOutputReason(reason, outputsize);
            choice = static_cast<unsigned short int>(reason.size() - 1) ;
        }
        MenuDataFiltersNextText(outputsize, oldchoice, 0);

        do {
            std::cout << "Enter: ";
            std::cin >> intvalue1;
            if ((std::cin.fail()) or (intvalue1 > choice)) { //clear input if it was bad
                std::cin.clear();
                std::cout << "invalid input, try again\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if ((object == 2) and (data == 2)) {
            strvalue1 = spec[intvalue1].species;
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            animal = FilterAnimal(animal, sign, intvalue2, strvalue1,
                strvalue2, strvalue2, intvalue2, floatvalue, intvalue2);
        }
        if ((object == 2) and (data == 3)) {
            strvalue1 = charac[intvalue1].breed;
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            animal = FilterAnimal(animal, sign, intvalue2, strvalue2,
                strvalue1, strvalue2, intvalue2, floatvalue, intvalue2);
        }
        if ((object == 2) and (data == 4)) {
            strvalue1 = gen[intvalue1].gender;
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            animal = FilterAnimal(animal, sign, intvalue2, strvalue2,
                strvalue2, strvalue1, intvalue2, floatvalue, intvalue2);
        }
        if ((object == 3) and (data == 5)) {
            strvalue1 = reason[intvalue1].reason;
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            app = FilterAppointment(app, sign, intvalue2, intvalue2, intvalue2,
                timevalue, strvalue1);
        }
        break;
    case 6:
        timevalue = InputDate();
        localtime_s(&date, &timevalue);
        Clear();
        if ((object == 3) and (data == 4)) {
            if (selected == 1) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            app = FilterAppointment(app, sign, intvalue2, intvalue2, intvalue2,
                timevalue, strvalue2);
        }
        break;
    }
}

void MenuDataFiltersText(int& outputsize, const short int choice) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2: //handling any owner case
        text = "Select a data to filter.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Number of Animals\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;

    case 3: //handling any animal case
        text = "Select a data to filter.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Specie\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Breed\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Gender\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Years of Age\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Weight\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4: //handling any appointment case
        text = "Select a data to filter.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Appointment ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Date\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Reason\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 7:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuDataFilters(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason) {

    short int choice;
    MenuDataFiltersText(outputsize, oldchoice);
    switch (oldchoice) {
    case 1:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFilters(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataFilters(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataFilters(outputsize, 4, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 2:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFiltersNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 1, 1, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataFiltersNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 1, 2, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 3:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFiltersNext(outputsize, 2, animal, owner, app,
                    spec, charac, gen, reason, 2, 1, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                if (spec.empty()) {
                    std::cout << "No data for Species found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataFiltersNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 2, 2, 0);
                }
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                if (charac.empty()) {
                    std::cout << "No data for Breed found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataFiltersNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 2, 3, 0);
                }
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                if (gen.empty()) {
                    std::cout << "No data for Gender found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataFiltersNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 2, 4, 0);
                }
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataFiltersNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 2, 5, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 6:
                Clear();
                MenuDataFiltersNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 2, 6, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 7:
                Clear();
                MenuDataFiltersNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 2, 7, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
        break;
    case 4:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFiltersNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 3, 1, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataFiltersNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 3, 2, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataFiltersNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 3, 3, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFiltersNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 3, 4, 0);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                if (reason.empty()) {
                    std::cout << "No data for Reason found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataFiltersNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 3, 5, 0);
                }
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 6:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 6);
        break;
    case 5:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFilters(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataFilters(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 6:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFilters(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataFilters(outputsize, 4, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 7:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataFilters(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataFilters(outputsize, 4, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataFiltersText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    }
}

void MenuDataSummaryNextText(int& outputsize, const short int choice,
 const unsigned short int selected) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Choose sign.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: < (less than)";
        if (selected == 1) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: <= (less than or equal to)";
        if (selected == 2) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: = (equal to)";
        if (selected == 3) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: != (not equal to)";
        if (selected == 4) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: >= (greater than or equal to)";
        if (selected == 5) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: > (greater than)";
        if (selected == 6) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Value\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2:
        text = "Choose sign.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: = (equal to)";
        if (selected == 3) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: != (not equal to)";
        if (selected == 4) {
            text = text + ": Selected\n";
        }
        else {
            text = text + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Value\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 3: //any unsigned int case
        text = "Write a positive natural number.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4: //any float case
        text = "Write a positive real number.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5: //any object string case
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the main menu\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6: //any date case
        text = "Write date and time in the folowing format: Day.Month.Year "
            "Hour:Minute. Year cannot be less than 1900.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuDataSummaryNext(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason, const unsigned short int object,
 const unsigned short int data, unsigned short int selected) {
    //object: 1 - owner  2 - animal  3 - appointment
    //data: respective data to object starting from 1

    unsigned short int choice;
    std::string text;
    unsigned int intvalue1;
    unsigned int intvalue2;
    std::string strvalue1;
    std::string strvalue2;
    float floatvalue;
    time_t timevalue;
    tm date = { 0 };
    std::vector<std::string> sign(5, "");

    if (!(oldchoice == 5)) {
        MenuDataSummaryNextText(outputsize, oldchoice, 0);
    }
    switch (oldchoice) {
    case 1:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                selected = choice;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 2:
                selected = choice;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 3:
                selected = choice;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 4:
                selected = choice;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 5:
                selected = choice;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 6:
                selected = choice;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 7:
                if (selected != 0) {
                    Clear();
                    if (((object == 1) and (data == 1)) or ((object == 2) and
                        (data == 4))) {
                        MenuDataSummaryNext(outputsize, 3, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    if ((object == 2) and (data == 5)) {
                        MenuDataSummaryNext(outputsize, 4, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    if ((object == 3) and (data == 3)) {
                        MenuDataSummaryNext(outputsize, 6, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    Clear();
                    MenuDataSummaryNextText(outputsize, oldchoice, selected);
                }
                else {
                    text = "Choose a sign\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                }
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
        break;
    case 2:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                selected = 3;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 2:
                selected = 4;
                Clear();
                MenuDataSummaryNextText(outputsize, oldchoice, selected);
                break;
            case 3:
                if (selected) {
                    Clear();
                    if (((object == 2) and (data == 1)) or ((object == 2) and
                        (data == 2)) or ((object == 2) and (data == 3)) or
                        ((object == 3) and (data == 4))) {
                        MenuDataSummaryNext(outputsize, 5, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    if (((object == 3) and (data == 1)) or ((object == 3) and
                        (data == 2))) {
                        MenuDataSummaryNext(outputsize, 3, animal, owner, app,
                            spec, charac, gen, reason, object, data, selected);
                    }
                    Clear();
                    MenuDataSummaryNextText(outputsize, oldchoice, selected);
                }
                else {
                    text = "Choose a sign\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                }
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 3:
        do {
            std::cout << "Enter: ";
            std::cin >> intvalue1;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cout << "invalid input, try again\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                break;
            }

        } while (true);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Clear();
        if ((object == 1) and (data == 1)) {
            text = "Number of records with Number of Animals ";
            if (selected == 1) {
                text = text + "< " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                text = text + "<= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                text = text + "= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                text = text + ">= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                text = text + "> " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            text = text + std::to_string(SummaryOwner(owner, intvalue1,
                sign[static_cast<unsigned __int64>(data - 1)])) + '\n';
        }
        if ((object == 2) and (data == 4)) {
            text = "Number of records with Years of Age ";
            if (selected == 1) {
                text = text + "< " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                text = text + "<= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                text = text + "= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                text = text + ">= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                text = text + "> " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            text = text + std::to_string(SummaryAnimal(animal, sign, strvalue1,
                strvalue2, strvalue2, intvalue1, floatvalue)) + '\n';

        }
        if ((object == 3) and (data == 1)) {
            text = "Number of records with Owner ID ";
            if (selected == 3) {
                text = text + "= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            text = text + std::to_string(SummaryAppointment(app, sign,
                intvalue1, intvalue2, timevalue, strvalue1)) + '\n';
        }
        if ((object == 3) and (data == 2)) {
            text = "Number of records with Animal ID ";
            if (selected == 3) {
                text = text + "= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + std::to_string(intvalue1) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            text = text + std::to_string(SummaryAppointment(app, sign,
                intvalue2, intvalue1, timevalue, strvalue1)) + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        AnyKeyReturn(outputsize);
        break;
    case 4:
        do {
            std::cout << "Enter: ";
            std::cin >> floatvalue;
            if ((std::cin.fail()) or (floatvalue <= 0)) {
                std::cin.clear();
                std::cout << "invalid input, try again\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (!(floatvalue) or (floatvalue <= 0));
        Clear();
        if ((object == 2) and (data == 5)) {
            text = "Number of records with Weight ";
            if (selected == 1) {
                text = text + "< " + std::to_string(floatvalue) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                text = text + "<= " + std::to_string(floatvalue) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                text = text + "= " + std::to_string(floatvalue) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + std::to_string(floatvalue) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                text = text + ">= " + std::to_string(floatvalue) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                text = text + "> " + std::to_string(floatvalue) + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            text = text + std::to_string(SummaryAnimal(animal, sign, strvalue1,
                strvalue1, strvalue1, intvalue1, floatvalue)) + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        AnyKeyReturn(outputsize);
        break;
    case 5:
        choice = 0;
        if ((object == 2) and (data == 1)) {
            TableOutputSpecies(spec, outputsize);
            choice = static_cast<unsigned short int>(spec.size() - 1) ;
        }
        if ((object == 2) and (data == 2)) {
            TableOutputCharacteristics(charac, outputsize);
            choice = static_cast<unsigned short int>(charac.size() - 1) ;
        }
        if ((object == 2) and (data == 3)) {
            TableOutputGender(gen, outputsize);
            choice = static_cast<unsigned short int>(gen.size() - 1) ;
        }
        if ((object == 3) and (data == 4)) {
            TableOutputReason(reason, outputsize);
            choice = static_cast<unsigned short int>(reason.size() - 1) ;
        }
        MenuDataSummaryNextText(outputsize, oldchoice, 0);

        do {
            std::cout << "Enter: ";
            std::cin >> intvalue1;
            if ((std::cin.fail()) or (intvalue1 > choice)) { //clear input if it was bad
                std::cin.clear();
                std::cout << "invalid input, try again\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Clear();

        if ((object == 2) and (data == 1)) {
            strvalue1 = spec[intvalue1].species;
            text = "Number of records with Species ";
            if (selected == 3) {
                text = text + "= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            text = text + std::to_string(SummaryAnimal(animal, sign, strvalue1,
                strvalue2, strvalue2, intvalue1, floatvalue)) + '\n';
        }
        if ((object == 2) and (data == 2)) {
            strvalue1 = charac[intvalue1].breed;
            text = "Number of records with Breed ";
            if (selected == 3) {
                text = text + "= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            text = text + std::to_string(SummaryAnimal(animal, sign, strvalue2,
                strvalue1, strvalue2, intvalue2, floatvalue)) + '\n';
        }
        if ((object == 2) and (data == 3)) {
            strvalue1 = gen[intvalue1].gender;
            text = "Number of records with Gender ";
            if (selected == 3) {
                text = text + "= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            text = text + std::to_string(SummaryAnimal(animal, sign, strvalue2,
                strvalue2, strvalue1, intvalue2, floatvalue)) + '\n';
        }
        if ((object == 3) and (data == 4)) {
            strvalue1 = reason[intvalue1].reason;
            text = "Number of records with Reason ";
            if (selected == 3) {
                text = text + "= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + strvalue1 + ": ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            text = text + std::to_string(SummaryAppointment(app, sign,
                intvalue2, intvalue2, timevalue, strvalue1)) + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        AnyKeyReturn(outputsize);
        break;
    case 6:
        timevalue = InputDate();
        localtime_s(&date, &timevalue);
        Clear();
        if ((object == 3) and (data == 3)) {
            text = "Number of records with Date ";
            if (selected == 1) {
                text = text + "< " + std::to_string(date.tm_mday) + "." +
                    std::to_string(date.tm_mon) + "." +
                    std::to_string(date.tm_year + 1900) + " " +
                    std::to_string(date.tm_hour) + ":" +
                    std::to_string(date.tm_min) + " : ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<";
            }
            if (selected == 2) {
                text = text + "<= " + std::to_string(date.tm_mday) + "." +
                    std::to_string(date.tm_mon) + "." +
                    std::to_string(date.tm_year + 1900) + " " +
                    std::to_string(date.tm_hour) + ":" +
                    std::to_string(date.tm_min) + " : ";
                sign[static_cast<unsigned __int64>(data - 1)] = "<=";
            }
            if (selected == 3) {
                text = text + "= " + std::to_string(date.tm_mday) + "." +
                    std::to_string(date.tm_mon) + "." +
                    std::to_string(date.tm_year + 1900) + " " +
                    std::to_string(date.tm_hour) + ":" +
                    std::to_string(date.tm_min) + " : ";
                sign[static_cast<unsigned __int64>(data - 1)] = "=";
            }
            if (selected == 4) {
                text = text + "!= " + std::to_string(date.tm_mday) + "." +
                    std::to_string(date.tm_mon) + "." +
                    std::to_string(date.tm_year + 1900) + " " +
                    std::to_string(date.tm_hour) + ":" +
                    std::to_string(date.tm_min) + " : ";
                sign[static_cast<unsigned __int64>(data - 1)] = "!=";
            }
            if (selected == 5) {
                text = text + ">= " + std::to_string(date.tm_mday) + "." +
                    std::to_string(date.tm_mon) + "." +
                    std::to_string(date.tm_year + 1900) + " " +
                    std::to_string(date.tm_hour) + ":" +
                    std::to_string(date.tm_min) + " : ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">=";
            }
            if (selected == 6) {
                text = text + "> " + std::to_string(date.tm_mday) + "." +
                    std::to_string(date.tm_mon) + "." +
                    std::to_string(date.tm_year + 1900) + " " +
                    std::to_string(date.tm_hour) + ":" +
                    std::to_string(date.tm_min) + " : ";
                sign[static_cast<unsigned __int64>(data - 1)] = ">";
            }
            text = text + std::to_string(SummaryAppointment(app, sign,
                intvalue2, intvalue2, timevalue, strvalue1)) + '\n';
        }
        Outputconverter(text, outputsize);
        std::cout << text;
        AnyKeyReturn(outputsize);
        break;
    }
}

void MenuDataSummaryText(int& outputsize, const short int choice) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Select an object for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2: //handling any owner case
        text = "Select an Owner data for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Number of Animals\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 3: //handling any animal case
        text = "Select an Animal data for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Specie\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Breed\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Gender\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Years of Age\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Weight\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4: //handling any appointment case
        text = "Select an Appointment data for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Date\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Reason\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "Select an object for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6:
        text = "Select an object for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 7:
        text = "Select an object for summary.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuDataSummary(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason) {

    short int choice;
    MenuDataSummaryText(outputsize, oldchoice);
    switch (oldchoice) {
    case 1:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSummary(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataSummary(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, 4, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 2:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSummaryNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 1, 1, 0);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 2);
        break;
    case 3:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                if (spec.empty()) {
                    std::cout << "No data for Species found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataSummaryNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 2, 1, 0);
                }
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                if (charac.empty()) {
                    std::cout << "No data for Breed found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataSummaryNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 2, 2, 0);
                }
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                if (gen.empty()) {
                    std::cout << "No data for Gender found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataSummaryNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 2, 3, 0);
                }
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataSummaryNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 2, 4, 0);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSummaryNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 2, 5, 0);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 6:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 6);
        break;
    case 4:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSummaryNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 3, 1, 0);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataSummaryNext(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason, 3, 2, 0);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummaryNext(outputsize, 1, animal, owner, app, spec,
                    charac, gen, reason, 3, 3, 0);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                if (reason.empty()) {
                    std::cout << "No data for Reason found\n";
                    AnyKeyReturn(outputsize);
                }
                else {
                    MenuDataSummaryNext(outputsize, 2, animal, owner, app,
                        spec, charac, gen, reason, 3, 4, 0);
                }
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 5:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 5);
        break;
    case 5:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSummary(outputsize, 2, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataSummary(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 6:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSummary(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataSummary(outputsize, 4, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 7:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataSummary(outputsize, 3, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataSummary(outputsize, 4, animal, owner, app, spec,
                    charac, gen, reason);
                Clear();
                MenuDataSummaryText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    }
}

void MenuDataShownText(int& outputsize, const short int choice,
 std::vector<bool>& ownershow, std::vector<bool>& animalshow,
 std::vector<bool>& appshow) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2: //handling any owner case
        text = "Toggle show for Owner.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner ID: " + bool_to_string(ownershow[0]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Full Name: " + bool_to_string(ownershow[1]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Number of Animals: " + bool_to_string(ownershow[2])
            + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;

    case 3: //handling any animal case
        text = "Toggle show for Animal.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal ID: " + bool_to_string(animalshow[0]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Name: " + bool_to_string(animalshow[1]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Specie: " + bool_to_string(animalshow[2]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Breed: " + bool_to_string(animalshow[3]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Gender: " + bool_to_string(animalshow[4]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Years of Age: " + bool_to_string(animalshow[5]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Weight: " + bool_to_string(animalshow[6]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Owner ID: " + bool_to_string(animalshow[7]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "9: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4: //handling any appointment case
        text = "Toggle show for Appointment.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Appointment ID: " + bool_to_string(appshow[0]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner ID: " + bool_to_string(appshow[1]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Animal ID: " + bool_to_string(appshow[2]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Date: " + bool_to_string(appshow[3]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Reason: " + bool_to_string(appshow[4]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Commentary: " + bool_to_string(appshow[5]) + "\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 7:
        text = "Select an object.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Appointment\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuDataShown(int& outputsize, const short int oldchoice,
 std::vector<bool>& ownershow, std::vector<bool>& animalshow,
 std::vector<bool>& appshow) {

    short int choice;
    MenuDataShownText(outputsize, oldchoice, ownershow, animalshow, appshow);
    switch (oldchoice) {
    case 1:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataShown(outputsize, 2, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, 3, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                Clear();
                MenuDataShown(outputsize, 4, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 2:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                ownershow[0] = !ownershow[0];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                ownershow[1] = !ownershow[1];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                ownershow[2] = !ownershow[2];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 3:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                animalshow[0] = !animalshow[0];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                animalshow[1] = !animalshow[1];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                animalshow[2] = !animalshow[2];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 4:
                animalshow[3] = !animalshow[3];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 5:
                animalshow[4] = !animalshow[4];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 6:
                animalshow[5] = !animalshow[5];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 7:
                animalshow[6] = !animalshow[6];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 8:
                animalshow[7] = !animalshow[7];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 9:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 9);
        break;
    case 4:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                appshow[0] = !appshow[0];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                appshow[1] = !appshow[1];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                appshow[2] = !appshow[2];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 4:
                appshow[3] = !appshow[3];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 5:
                appshow[4] = !appshow[4];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 6:
                appshow[5] = !appshow[5];
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 7:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 7);
        break;
    case 5:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataShown(outputsize, 2, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, 3, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 6:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataShown(outputsize, 3, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, 4, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 7:
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuDataShown(outputsize, 3, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, 4, ownershow, animalshow, appshow);
                Clear();
                MenuDataShownText(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    }
}

void MenuShowObjectsAuxiliaryText(int& outputsize) {

    std::string text;
    text = "Choose an auxiliary object to display.\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;

    text = "1: Species\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "2: Specie Breed\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "3: Animal Gender\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "4: Appointment Reason\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "5: Return\n";
    Outputconverter(text, outputsize);
    std::cout << text;

}

void MenuShowObjectsAuxiliary(int& outputsize, char& border,
 std::vector<Species>& spec, std::vector<Characteristics>& charac,
 std::vector<Gender>& gen, std::vector<Reason>& reason) {

    MenuShowObjectsAuxiliaryText(outputsize);
    short int choice;
    do {
        choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            Clear();
            if (spec.empty()) {
                std::cout << "No data for Species found\n";
            }
            else {
                TableOutputSpecies(spec, outputsize, border);
            }
            AnyKeyReturn(outputsize);
            Clear();
            MenuShowObjectsAuxiliaryText(outputsize);
            break;
        case 2:
            Clear();
            if (charac.empty()) {
                std::cout << "No data for Specie Breed found\n";
            }
            else {
                TableOutputCharacteristics(charac, outputsize, border);
            }
            AnyKeyReturn(outputsize);
            Clear();
            MenuShowObjectsAuxiliaryText(outputsize);
            break;
        case 3:
            Clear();
            if (gen.empty()) {
                std::cout << "No data for Animal Gender found\n";
            }
            else {
                TableOutputGender(gen, outputsize, border);
            }
            AnyKeyReturn(outputsize);
            Clear();;
            MenuShowObjectsAuxiliaryText(outputsize);
            break;
        case 4:
            Clear();
            if (reason.empty()) {
                std::cout << "No data for Appointment Reason found\n";
            }
            else {
                TableOutputReason(reason, outputsize, border);
            }
            AnyKeyReturn(outputsize);
            Clear();
            MenuShowObjectsAuxiliaryText(outputsize);
            break;
        case 5:
            break;
        }
    } while (choice != 5);
}

void MenuShowObjectsMainText(int& outputsize, short int& choice) {

    std::string text;
    text = "Filtering and sorting applied will reset if you go back to the "
        "previous menu.\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;

    switch (choice) {
    case 1:
        text = "1: Show objects\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Owners\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Restore Animals\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Restore Appointments\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "9: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2:
        text = "1: Show object\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Owners\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;

    case 3:
        text = "1: Show object\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Animals\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4:
        text = "1: Show object\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Appointments\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "1: Show objects\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Owners\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Restore Animals\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6:
        text = "1: Show objects\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Owners\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Restore Appointments\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 7:
        text = "1: Show objects\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Data to be shown\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Show summary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Filters\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Sorting\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Restore Animals\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Restore Appointments\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuShowObjectsMain(int& outputsize, char& border, short int& oldchoice,
 std::vector<Animal>& origanimal, std::vector<Owner>& origowner,
 std::vector<Appointment>& origapp, std::vector<Species>& origspec,
 std::vector<Characteristics>& origchar, std::vector<Gender>& origgen,
 std::vector<Reason>& origreason) {

    short int choice;
    std::vector<bool> ownershow;
    std::vector<bool> animalshow;
    std::vector<bool> appshow;
    std::vector<Owner> newowner;
    std::vector<Animal> newanimal;
    std::vector<Appointment> newapp;
    std::vector<unsigned short int> prio(8, 0);
    std::vector<std::string> sign(8, "dec");

    MenuShowObjectsMainText(outputsize, oldchoice);
    if (oldchoice == 1) { //swith statement does not allow new variable
    //initialisation so I use if statement for better memmory usage
        newowner = origowner;
        newanimal = origanimal;
        newapp = origapp;
        ownershow = std::vector<bool>(3, true);
        animalshow = std::vector<bool>(8, true);
        appshow = std::vector<bool>(6, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputOwner(newowner, outputsize, border, ownershow);
                TableOutputAnimal(newanimal, outputsize, border, animalshow);
                TableOutputAppointment(newapp, outputsize, border, appshow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newowner = origowner;
                std::cout << "Restored\n";
                break;
            case 7:
                newanimal = origanimal;
                std::cout << "Restored\n";
                break;
            case 8:
                newapp = origapp;
                std::cout << "Restored\n";
                break;
            case 9:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 9);
    }
    if (oldchoice == 2) {
        newowner = origowner;
        ownershow = std::vector<bool>(3, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputOwner(newowner, outputsize, border, ownershow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newowner = origowner;
                std::cout << "Restored\n";
                break;
            case 7:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 7);
    }
    if (oldchoice == 3) {
        newanimal = origanimal;
        animalshow = std::vector<bool>(8, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputAnimal(newanimal, outputsize, border, animalshow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newanimal = origanimal;
                std::cout << "Restored\n";
                break;
            case 7:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 7);
    }
    if (oldchoice == 4) {
        newapp = origapp;
        appshow = std::vector<bool>(6, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputAppointment(newapp, outputsize, border, appshow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newapp = origapp;
                std::cout << "Restored\n";
                break;
            case 7:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 7);
    }
    if (oldchoice == 5) {
        newowner = origowner;
        newanimal = origanimal;
        ownershow = std::vector<bool>(3, true);
        animalshow = std::vector<bool>(8, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputOwner(newowner, outputsize, border, ownershow);
                TableOutputAnimal(newanimal, outputsize, border, animalshow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newowner = origowner;
                std::cout << "Restored\n";
                break;
            case 7:
                newanimal = origanimal;
                std::cout << "Restored\n";
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
    }
    if (oldchoice == 6) {
        newowner = origowner;
        newapp = origapp;
        ownershow = std::vector<bool>(3, true);
        appshow = std::vector<bool>(6, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputOwner(newowner, outputsize, border, ownershow);
                TableOutputAppointment(newapp, outputsize, border, appshow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newowner = origowner;
                std::cout << "Restored\n";
                break;
            case 7:
                newapp = origapp;
                std::cout << "Restored\n";
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
    }
    if (oldchoice == 7) {
        newanimal = origanimal;
        newapp = origapp;
        animalshow = std::vector<bool>(8, true);
        appshow = std::vector<bool>(6, true);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                TableOutputAnimal(newanimal, outputsize, border, animalshow);
                TableOutputAppointment(newapp, outputsize, border, appshow);
                AnyKeyReturn(outputsize);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuDataShown(outputsize, oldchoice, ownershow, animalshow,
                    appshow);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuDataSummary(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuDataFilters(outputsize, oldchoice, newanimal, newowner,
                    newapp, origspec, origchar, origgen, origreason);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuDataSorting(outputsize, oldchoice, newanimal, newowner,
                    newapp, prio, sign);
                Clear();
                MenuShowObjectsMainText(outputsize, oldchoice);
                break;
            case 6:
                newanimal = origanimal;
                std::cout << "Restored\n";
                break;
            case 7:
                newapp = origapp;
                std::cout << "Restored\n";
                break;
            case 8:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 8);
    }
}

void MenuShowObjectsText(int& outputsize) {
    std::string text;
    text = "Choose an object/s.\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "1: Show all main objects\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "2: Show Owner data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "3: Show Animal data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "4: Show Appointment data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "5: Show Owner + Animal data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "6: Show Owner + Appointment data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "7: Show Animal + Appointment data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "8: Auxiliary objects\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "9: Return\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
}

void MenuShowObjects(int& outputsize, char& border,
 std::vector<Species>& origspec, std::vector<Characteristics>& origchar,
 std::vector<Gender>& origgen, std::vector<Animal>& origanimal,
 std::vector<Owner>& origowner, std::vector<Reason>& origreason,
 std::vector<Appointment>& origapp) {

    MenuShowObjectsText(outputsize);
    short int choice;
    do {
        choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
            Clear();
            if (origowner.empty()) {
                std::cout << "No data for Owner found\n";
            }
            if (origanimal.empty()) {
                std::cout << "No data for Animal found\n";
            }
            if (origapp.empty()) {
                std::cout << "No data for Appointment found\n";
            }
            if (!((origowner.empty()) or (origanimal.empty()) or
                (origapp.empty()))) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 2:
            Clear();
            if (origowner.empty()) {
                std::cout << "No data for Owner found\n";
            }
            if (!(origowner.empty())) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 3:
            Clear();
            if (origanimal.empty()) {
                std::cout << "No data for Animal found\n";
            }
            if (!(origanimal.empty())) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 4:
            Clear();
            if (origapp.empty()) {
                std::cout << "No data for Appointment found\n";
            }
            if (!(origapp.empty())) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 5:
            Clear();
            if (origowner.empty()) {
                std::cout << "No data for Owner found\n";
            }
            if (origanimal.empty()) {
                std::cout << "No data for Animal found\n";
            }
            if (!((origowner.empty()) or (origanimal.empty()))) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 6:
            Clear();
            if (origowner.empty()) {
                std::cout << "No data for Owner found\n";
            }
            if (origapp.empty()) {
                std::cout << "No data for Appointment found\n";
            }
            if (!((origowner.empty()) or (origapp.empty()))) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 7:
            Clear();
            if (origanimal.empty()) {
                std::cout << "No data for Animal found\n";
            }
            if (origapp.empty()) {
                std::cout << "No data for Appointment found\n";
            }
            if (!((origanimal.empty()) or (origapp.empty()))) {
                MenuShowObjectsMain(outputsize, border, choice, origanimal,
                    origowner, origapp, origspec, origchar, origgen,
                    origreason);
            }
            else {
                AnyKeyReturn(outputsize);
            }
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 8:
            Clear();
            MenuShowObjectsAuxiliary(outputsize, border, origspec,
                origchar, origgen, origreason);
            Clear();
            MenuShowObjectsText(outputsize);
            break;
        case 9:
            break;
        default: std::cout << "invalid input, try again\n"; break;
        }
    } while (choice != 9);
}

void MenuAddObjectsText(int& outputsize) {

    std::string text;
    text = "Choose an object to add.\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "1: Owner\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "2: Animal\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "3: Appointment\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "4: Species\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "5: Specie Breed\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "6: Animal Gender\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "7: Appointment Reason\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "8: Return\n";
    Outputconverter(text, outputsize);
    std::cout << text;
}

void MenuAddOwner(int& outputsize, char& border, std::vector<Owner>& owner,
 std::string& ownerfile, std::string& animalfile) {

    std::string text;
    std::string inputstr1;
    char inputchar;
    Owner newowner;
    bool check = true;
    do {
        text = "Write a natural non negative number for Owner ID: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newowner.owner_id;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input, try again\n";
        }
        else {
            check = false;
            for (auto& o : owner) {
                if (o.owner_id == newowner.owner_id) {
                    text = "Owner ID must be unique\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                    check = true;
                }
            }
        }
    } while (check);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        text = "Write a string of 80 characters maximum for Owner Full"
            " Name: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 80) {
                    do {
                        text = "Your text is more than 80 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 80);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        strcpy_s(newowner.full_name, inputstr1.c_str());
                        break;
                    }
                }
                else {
                    strcpy_s(newowner.full_name, inputstr1.c_str());
                    break;
                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Owner> newownervector;
    newownervector.push_back(newowner);
    std::vector<bool> show(3, true);
    Clear();
    TableOutputOwner(newownervector, outputsize, border, show);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                owner.push_back(newowner);
                SaveOwner(owner, ownerfile);
                UpdateNoAOwner(ownerfile, animalfile);
                ReadOwner(owner, ownerfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddAnimal(int& outputsize, char& border, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Species>& spec, std::vector<Characteristics>& charac,
 std::vector<Gender>& gen) {

    std::string text;
    std::string inputstr1;
    unsigned int inputint;
    char inputchar;
    Animal newanimal;
    bool check = true;
    do {
        text = "Write a natural non negative number for Animal ID: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newanimal.animal_id;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            check = false;
            for (auto& a : animal) {
                if (a.animal_id == newanimal.animal_id) {
                    text = "Animal ID must be unique\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                    check = true;
                }
            }
        }
    } while (check);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        text = "Write a string of 60 characters maximum for Animal Name: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 60) {
                    do {
                        text = "Your text is more than 60 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 60);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        strcpy_s(newanimal.name, inputstr1.c_str());
                        break;
                    }
                }
                else {
                    strcpy_s(newanimal.name, inputstr1.c_str());
                    break;
                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    TableOutputSpecies(spec, outputsize);
    do {
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the menu of the respective object.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> inputint;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            if (inputint < spec.size()) {
                newanimal.characteristics.species = spec[inputint];
                break;
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    std::vector<Characteristics> newcharac = charac;
    size_t n = 0;
    while (n < newcharac.size()) {
        if (Removespaces(newcharac[n].species.species) != 
            Removespaces(newanimal.characteristics.species.species)) {
            newcharac.erase(newcharac.begin() + static_cast<__int64>(n));
        }
        else {
            n++;
        }

    }
    if (newcharac.empty()) {
        text = "No breeds found with this specie, add more from the respective"
            " menu.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        AnyKeyReturn(outputsize);
        return;
    }

    TableOutputCharacteristics(newcharac, outputsize);
    do {
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the menu of the respective object.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> inputint;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            if (inputint < newcharac.size()) {
                newanimal.characteristics = newcharac[inputint];
                break;
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    TableOutputGender(gen, outputsize);
    do {
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the menu of the respective object.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> inputint;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            if (inputint < gen.size()) {
                newanimal.gender = gen[inputint];
                break;
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    do {
        text = "Write a natural non negative number for Years of Age: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newanimal.age;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        text = "Write a real positive number for Weight: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newanimal.weight;
        if ((std::cin.fail()) or (newanimal.weight <= 0)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        text = "Write a natural non negative number for Owner ID: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newanimal.owner_id;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Animal> newanimalvector;
    newanimalvector.push_back(newanimal);
    std::vector<bool> show(8, true);
    Clear();
    TableOutputAnimal(newanimalvector, outputsize, border, show);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                animal.push_back(newanimal);
                SaveAnimal(animal, animalfile);
                UpdateNoAOwner(ownerfile, animalfile);
                ReadOwner(owner, ownerfile);
                ReadAnimal(animal, animalfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddAppointment(int& outputsize, char& border,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Reason>& reason) {

    std::string text;
    std::string inputstr1;
    unsigned int inputint;
    char inputchar;
    Appointment newapp;
    bool check = true;
    do {
        text = "Write a natural non negative number for Appointment ID: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newapp.appointment_id;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            check = false;
            for (auto& a : app) {
                if (a.appointment_id == newapp.appointment_id) {
                    text = "Appointment ID must be unique\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                    check = true;
                }
            }
        }
    } while (check);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        text = "Write a natural non negative number for Owner ID: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newapp.owner_id;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        text = "Write a natural non negative number for Animal ID: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> newapp.animal_id;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    text = "Write date and time in the folowing format: Day.Month.Year "
        "Hour:Minute. Year cannot be less than 1900.\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    newapp.date = InputDate();

    TableOutputReason(reason, outputsize);
    do {
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the menu of the respective object.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> inputint;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            if (inputint < reason.size()) {
                newapp.reason = reason[inputint];
                break;
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    do {
        text = "Write a string of 160 characters maximum for Commentary: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 160) {
                    do {
                        text = "Your text is more than 160 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 160);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        strcpy_s(newapp.commentary, inputstr1.c_str());
                        break;
                    }
                }
                else {
                    strcpy_s(newapp.commentary, inputstr1.c_str());
                    break;
                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    std::vector<Appointment> newappvector;
    newappvector.push_back(newapp);
    std::vector<bool> show(6, true);
    Clear();
    TableOutputAppointment(newappvector, outputsize, border, show);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                app.push_back(newapp);
                SaveAppointment(app, appfile);
                ReadAppointment(app, appfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddSpecies(int& outputsize, std::vector<Species>& spec,
 std::string& specfile) {

    std::string text;
    std::string inputstr1;
    char inputchar;
    Species newspec;
    bool check = true;

    do {
        text = "Write a string of 60 characters maximum for Animal Specie: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 60) {
                    do {
                        text = "Your text is more than 60 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 60);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        check = true;
                        for (auto& s : spec) {
                            if (s.species == inputstr1) {
                                text = "Animal Specie must be unique\n";
                                Outputconverter(text, outputsize);
                                std::cout << text;
                                check = false;
                            }
                        }
                        if (check) {
                            strcpy_s(newspec.species, inputstr1.c_str());
                            break;
                        }
                    }
                }
                else {
                    check = true;
                    for (auto& s : spec) {
                        if (s.species == inputstr1) {
                            text = "Animal Specie must be unique\n";
                            Outputconverter(text, outputsize);
                            std::cout << text;
                            check = false;
                        }
                    }
                    if (check) {
                        strcpy_s(newspec.species, inputstr1.c_str());
                        break;
                    }

                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    std::vector<Species> newspecvector;
    newspecvector.push_back(newspec);
    TableOutputSpecies(newspecvector, outputsize);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                spec.push_back(newspec);
                SaveSpecies(spec, specfile);
                ReadSpecies(spec, specfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddCharacteristics(int& outputsize,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Species>& spec) {

    std::string text;
    std::string inputstr1;
    unsigned int inputint;
    char inputchar;
    Characteristics newcharac;
    bool check = true;

    TableOutputSpecies(spec, outputsize);
    do {
        text = "Choose an object by writing a number after the \"*\". You can"
            " add more objects from the menu of the respective object.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::cin >> inputint;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            if (inputint < spec.size()) {
                newcharac.species = spec[inputint];
                break;
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    do {
        text = "Write a string of 60 characters maximum for Specie Breed: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 60) {
                    do {
                        text = "Your text is more than 60 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 60);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        check = true;
                        for (auto& c : charac) {
                            if (Removespaces(c.breed) == inputstr1) {
                                text = "Specie Breed must be unique\n";
                                Outputconverter(text, outputsize);
                                std::cout << text;
                                check = false;
                            }
                        }
                        if (check) {
                            strcpy_s(newcharac.breed, inputstr1.c_str());
                            break;
                        }
                    }
                }
                else {
                    check = true;
                    for (auto& c : charac) {
                        if (Removespaces(c.breed) == inputstr1) {
                            text = "Specie Breed must be unique\n";
                            Outputconverter(text, outputsize);
                            std::cout << text;
                            check = false;
                        }
                    }
                    if (check) {
                        strcpy_s(newcharac.breed, inputstr1.c_str());
                        break;
                    }

                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    std::vector<Characteristics> newcharacvector;
    newcharacvector.push_back(newcharac);
    TableOutputCharacteristics(newcharacvector, outputsize);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                charac.push_back(newcharac);
                SaveCharacteristics(charac, characfile);
                ReadCharacteristics(charac, characfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddGender(int& outputsize, std::vector<Gender>& gen,
 std::string& genfile) {

    std::string text;
    std::string inputstr1;
    char inputchar;
    Gender newgen;
    bool check = true;

    do {
        text = "Write a string of 60 characters maximum for Animal Gender: ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 60) {
                    do {
                        text = "Your text is more than 60 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 60);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        check = true;
                        for (auto& g : gen) {
                            if (Removespaces(g.gender) == inputstr1) {
                                text = "Animal Gender must be unique\n";
                                Outputconverter(text, outputsize);
                                std::cout << text;
                                check = false;
                            }
                        }
                        if (check) {
                            strcpy_s(newgen.gender, inputstr1.c_str());
                            break;
                        }
                    }
                }
                else {
                    check = true;
                    for (auto& g : gen) {
                        if (Removespaces(g.gender) == inputstr1) {
                            text = "Animal Gender must be unique\n";
                            Outputconverter(text, outputsize);
                            std::cout << text;
                            check = false;
                        }
                    }
                    if (check) {
                        strcpy_s(newgen.gender, inputstr1.c_str());
                        break;
                    }

                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    std::vector<Gender> newnewgenvector;
    newnewgenvector.push_back(newgen);
    TableOutputGender(newnewgenvector, outputsize);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                gen.push_back(newgen);
                SaveGender(gen, genfile);
                ReadGender(gen, genfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddReason(int& outputsize, std::vector<Reason>& reason,
 std::string& reasonfile) {

    std::string text;
    std::string inputstr1;
    char inputchar;
    Reason newreason;
    bool check = true;

    do {
        text = "Write a string of 60 characters maximum for Appointment Reason"
         ": ";
        Outputconverter(text, outputsize);
        std::cout << text;
        std::getline(std::cin, inputstr1);
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            inputstr1 = Removespaces(inputstr1);
            if (!(inputstr1.empty())) {
                if (inputstr1.size() > 60) {
                    do {
                        text = "Your text is more than 60 characters, do you "
                            "want to crop it?";
                        Outputconverter(text, outputsize);
                        text = text + "\nY: yes  N: no\n";
                        std::cout << text;
                        std::cin >> inputchar;
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (std::tolower(inputchar) == 'y') {
                                StringBounder(inputstr1, 60);
                                break;
                            }
                            if (std::tolower(inputchar) == 'n') {
                                break;
                            }
                        }
                    } while (true);
                    if (!(inputstr1.empty())) {
                        check = true;
                        for (auto& r : reason) {
                            if (Removespaces(r.reason) == inputstr1) {
                                text = "Appointment Reason must be unique\n";
                                Outputconverter(text, outputsize);
                                std::cout << text;
                                check = false;
                            }
                        }
                        if (check) {
                            strcpy_s(newreason.reason, inputstr1.c_str());
                            break;
                        }
                    }
                }
                else {
                    check = true;
                    for (auto& r : reason) {
                        if (Removespaces(r.reason) == inputstr1) {
                            text = "Appointment Reason must be unique\n";
                            Outputconverter(text, outputsize);
                            std::cout << text;
                            check = false;
                        }
                    }
                    if (check) {
                        strcpy_s(newreason.reason, inputstr1.c_str());
                        break;
                    }

                }
            }
        }
    } while (true);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Clear();

    std::vector<Reason> newreasonvector;
    newreasonvector.push_back(newreason);
    TableOutputReason(newreasonvector, outputsize);
    do {
        text = "Confirm?";
        Outputconverter(text, outputsize);
        text = text + "\nY: yes  N: no\n";
        std::cout << text;
        std::cin >> inputchar;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::
                streamsize>::max(), '\n');
            if (std::tolower(inputchar) == 'y') {
                reason.push_back(newreason);
                SaveReason(reason, reasonfile);
                ReadReason(reason, reasonfile);
                break;
            }
            if (std::tolower(inputchar) == 'n') {
                break;
            }
        }
    } while (true);
}

void MenuAddObjects(int& outputsize, char& border, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile) {

    MenuAddObjectsText(outputsize);
    short int choice;
    do {
        choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            Clear();
            MenuAddOwner(outputsize, border, owner, ownerfile, animalfile);
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 2:
            Clear();
            if ((spec.empty()) or (charac.empty()) or (gen.empty())) {
                if (spec.empty()) {
                    std::cout << "No data for Species found, add it first\n";
                }
                if (charac.empty()) {
                    std::cout << "No data for Species Breed found, add it"
                        " first\n";
                }
                if (gen.empty()) {
                    std::cout << "No data for Animal Gender found, add it"
                        " first\n";
                }
                AnyKeyReturn(outputsize);
            }
            else {
                MenuAddAnimal(outputsize, border, animal, animalfile, owner,
                    ownerfile, spec, charac, gen);
            }
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 3:
            Clear();
            if (reason.empty()) {
                std::cout << "No data for Appointment Reason found, add it"
                    " first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuAddAppointment(outputsize, border, app, appfile,
                    reason);
            }
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 4:
            Clear();
            MenuAddSpecies(outputsize, spec, specfile);
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 5:
            Clear();
            if (spec.empty()) {
                std::cout << "No data for Species found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuAddCharacteristics(outputsize, charac,
                    characfile, spec);
            }
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 6:
            Clear();
            MenuAddGender(outputsize, gen, genfile);
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 7:
            Clear();
            MenuAddReason(outputsize, reason, reasonfile);
            Clear();
            MenuAddObjectsText(outputsize);
            break;
        case 8:
            break;
        }
    } while (choice != 8);
}

void MenuRemoveObjectsNextText(int& outputsize, const short int choice) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Select data to match for deletion.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2:
        text = "Select a data to match for deletion.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;

    case 3:
        text = "Select a data to match for deletion.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Appointment ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4:
        text = "Choose an object to delete by writing a number after the"
            " \"*\". Write \"-1\" to return.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "Select how to delete Owner.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Just Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner + all animals tied to its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Owner + all appointments tied to its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Owner + all animals and appointments tied to its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuRemoveObjectsNext(int& outputsize, char& border,
 const short int oldchoice, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile) {

    unsigned short int choice;
    unsigned short int choice2;
    unsigned int intinput;
    int intinput2;
    char inputchar;
    bool check1;
    switch (oldchoice) {
    case 1:
        MenuRemoveObjectsNextText(outputsize, oldchoice);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuRemoveObjectsNextText(outputsize, 5);
                choice2 = 0;
                do {
                    std::cout << "Enter your choice: ";
                    std::cin >> choice2;
                    if (std::cin.fail()) {	//clear input if it was bad
                        std::cin.clear();
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                     , '\n');

                    if ((choice2 > 0) and (choice2 < 6)) {
                        if (choice2 == 5) {
                            break;
                        }
                        Clear();
                        do {
                            check1 = true;
                            std::cout << "Enter Owner ID: ";
                            std::cin >> intinput;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits
                                    <std::streamsize>::max(), '\n');
                                std::cout << "invalid input, try again\n";
                            }
                            else {
                                check1 = false;
                                for (auto& o : owner) {
                                    if (o.owner_id == intinput) {
                                        check1 = true;
                                        break;
                                    }
                                }
                                if (check1) {
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                    do {
                                        std::cout << "Confirm deletion?"
                                            "\nY: yes  N: no\n";
                                        std::cin >> inputchar;
                                        if (std::cin.fail()) {
                                            std::cin.clear();
                                            std::cin.ignore(std::
                                             numeric_limits<std::streamsize>::
                                             max(), '\n');
                                        }
                                        else {
                                            std::cin.ignore(std::
                                             numeric_limits<std::streamsize>::
                                              max(), '\n');
                                            if (std::tolower(inputchar)
                                                == 'y') {
                                                DeleteDataOwner(owner, app,
                                                 animal, intinput, ownerfile,
                                                 appfile, animalfile, choice2);
                                                ReadOwner(owner, ownerfile);
                                                check1 = false;
                                                MenuRemoveObjectsNextText(
                                                    outputsize, 5);
                                                break;
                                            }
                                            if (std::tolower(inputchar)
                                                == 'n') {
                                                check1 = false;
                                                Clear();
                                                MenuRemoveObjectsNextText(
                                                    outputsize, 5);
                                                break;
                                            }
                                        }
                                    } while (true);
                                }
                                else {
                                    check1 = true;
                                    std::cout << "No data with that ID\n";
                                }
                            }
                        } while (check1);
                    }
                    else {
                        std::cout << "invalid input, try again\n";
                    }
                } while (choice2 != 5);
                Clear();
                MenuRemoveObjectsNextText(outputsize, oldchoice);
                break;
            case 2:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 2);
        break;
    case 2:
        MenuRemoveObjectsNextText(outputsize, oldchoice);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                do {
                    check1 = true;
                    std::cout << "Enter Animal ID: ";
                    std::cin >> intinput;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        std::cout << "invalid input, try again\n";
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        check1 = false;
                        for (auto& a : animal) {
                            if (a.animal_id == intinput) {
                                check1 = true;
                                break;
                            }
                        }
                        if (check1) {
                            do {
                                std::cout << "Confirm deletion?"
                                    "\nY: yes  N: no\n";
                                std::cin >> inputchar;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                }
                                else {
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                    if (std::tolower(inputchar) == 'y') {
                                        DeleteDataAnimal(animal, intinput,
                                            animalfile, choice);
                                        ReadAnimal(animal, animalfile);
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                    if (std::tolower(inputchar) == 'n') {
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                }
                            } while (true);
                        }
                        else {
                            check1 = true;
                            std::cout << "No data with that ID\n";
                        }
                    }
                } while (check1);
                Clear();
                MenuRemoveObjectsNextText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                do {
                    check1 = true;
                    std::cout << "Enter Owner ID: ";
                    std::cin >> intinput;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        std::cout << "invalid input, try again\n";
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        check1 = false;
                        for (auto& a : animal) {
                            if (a.owner_id == intinput) {
                                check1 = true;
                                break;
                            }
                        }
                        if (check1) {
                            do {
                                std::cout << "Confirm deletion?"
                                    "\nY: yes  N: no\n";
                                std::cin >> inputchar;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                }
                                else {
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                    if (std::tolower(inputchar) == 'y') {
                                        DeleteDataAnimal(animal, intinput,
                                            animalfile, choice);
                                        ReadAnimal(animal, animalfile);
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                    if (std::tolower(inputchar) == 'n') {
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                }
                            } while (true);
                        }
                        else {
                            check1 = true;
                            std::cout << "No data with that ID\n";
                        }
                    }
                } while (check1);
                Clear();
                MenuRemoveObjectsNextText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 3:
        MenuRemoveObjectsNextText(outputsize, oldchoice);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                do {
                    check1 = true;
                    std::cout << "Enter Appointment ID: ";
                    std::cin >> intinput;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        std::cout << "invalid input, try again\n";
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        check1 = false;
                        for (auto& a : app) {
                            if (a.appointment_id == intinput) {
                                check1 = true;
                                break;
                            }
                        }
                        if (check1) {
                            do {
                                std::cout << "Confirm deletion?"
                                    "\nY: yes  N: no\n";
                                std::cin >> inputchar;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                }
                                else {
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                    if (std::tolower(inputchar) == 'y') {
                                        DeleteDataAppointment(app, intinput,
                                            appfile, choice);
                                        ReadAppointment(app, appfile);
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                    if (std::tolower(inputchar) == 'n') {
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                }
                            } while (true);
                        }
                        else {
                            check1 = true;
                            std::cout << "No data with that ID\n";
                        }
                    }
                } while (check1);
                Clear();
                MenuRemoveObjectsNextText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                do {
                    check1 = true;
                    std::cout << "Enter Owner ID: ";
                    std::cin >> intinput;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        std::cout << "invalid input, try again\n";
                    }
                    else {
                        check1 = false;
                        for (auto& a : app) {
                            if (a.owner_id == intinput) {
                                check1 = true;
                                break;
                            }
                        }
                        if (check1) {
                            do {
                                std::cout << "Confirm deletion?"
                                    "\nY: yes  N: no\n";
                                std::cin >> inputchar;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                }
                                else {
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                    if (std::tolower(inputchar) == 'y') {
                                        DeleteDataAppointment(app, intinput,
                                            appfile, choice);
                                        ReadAppointment(app, appfile);
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                    if (std::tolower(inputchar) == 'n') {
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                }
                            } while (true);
                        }
                        else {
                            check1 = true;
                            std::cout << "No data with that ID\n";
                        }
                    }
                } while (check1);
                Clear();
                MenuRemoveObjectsNextText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                do {
                    check1 = true;
                    std::cout << "Enter Animal ID: ";
                    std::cin >> intinput;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        std::cout << "invalid input, try again\n";
                    }
                    else {
                        check1 = false;
                        for (auto& a : app) {
                            if (a.animal_id == intinput) {
                                check1 = true;
                                break;
                            }
                        }
                        if (check1) {
                            do {
                                std::cout << "Confirm deletion?"
                                    "\nY: yes  N: no\n";
                                std::cin >> inputchar;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                }
                                else {
                                    std::cin.ignore(std::numeric_limits<std::
                                        streamsize>::max(), '\n');
                                    if (std::tolower(inputchar) == 'y') {
                                        DeleteDataAppointment(app, intinput,
                                            appfile, choice);
                                        ReadAppointment(app, appfile);
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                    if (std::tolower(inputchar) == 'n') {
                                        MenuRemoveObjectsNextText(outputsize,
                                            oldchoice);
                                        break;
                                    }
                                }
                            } while (true);
                        }
                        else {
                            check1 = true;
                            std::cout << "No data with that ID\n";
                        }
                    }
                } while (check1);
                Clear();
                MenuRemoveObjectsNextText(outputsize, oldchoice);
                break;
            case 4:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 4);
        break;
    case 4:
        TableOutputSpecies(spec, outputsize, border);
        MenuRemoveObjectsNextText(outputsize, 5);
        do {
            intinput2 = 0;
            std::cout << "Enter your choice: ";
            std::cin >> intinput2;
            if ((std::cin.fail()) or (intinput2 < -1) or (intinput2 >=
                static_cast<int>(spec.size()))) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                std::cout << "invalid input, try again\n";
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (intinput2 == -1) {
                    break;
                }
                do {
                    std::cout << "Confirm deletion of object *"
                        + std::to_string(intinput2) + "?\nY: yes  N: no\n";
                    std::cin >> inputchar;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        if (std::tolower(inputchar) == 'y') {
                            spec.erase(spec.begin() + intinput2);
                            SaveSpecies(spec, specfile);
                            ReadSpecies(spec, specfile);
                            TableOutputSpecies(spec, outputsize, border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                        if (std::tolower(inputchar) == 'n') {
                            Clear();
                            TableOutputSpecies(spec, outputsize, border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                    }
                } while (true);
            }
        } while (true);
        break;
    case 5:
        TableOutputCharacteristics(charac, outputsize, border);
        MenuRemoveObjectsNextText(outputsize, 5);
        do {
            intinput2 = 0;
            std::cout << "Enter your choice: ";
            std::cin >> intinput2;
            if ((std::cin.fail()) or (intinput2 < -1) or (intinput2 >=
                static_cast<int>(charac.size()))) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                std::cout << "invalid input, try again\n";
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (intinput2 == -1) {
                    break;
                }
                do {
                    std::cout << "Confirm deletion of object *"
                        + std::to_string(intinput2) + "?\nY: yes  N: no\n";
                    std::cin >> inputchar;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        if (std::tolower(inputchar) == 'y') {
                            charac.erase(charac.begin() + intinput2);
                            SaveCharacteristics(charac, characfile);
                            ReadCharacteristics(charac, characfile);
                            TableOutputCharacteristics(charac, outputsize,
                                border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                        if (std::tolower(inputchar) == 'n') {
                            Clear();
                            TableOutputCharacteristics(charac, outputsize,
                                border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                    }
                } while (true);
            }
        } while (true);
        break;
    case 6:
        TableOutputGender(gen, outputsize, border);
        MenuRemoveObjectsNextText(outputsize, 5);
        do {
            intinput2 = 0;
            std::cout << "Enter your choice: ";
            std::cin >> intinput2;
            if ((std::cin.fail()) or (intinput2 < -1) or (intinput2 >=
                static_cast<int>(gen.size()))) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                std::cout << "invalid input, try again\n";
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (intinput2 == -1) {
                    break;
                }
                do {
                    std::cout << "Confirm deletion of object *"
                        + std::to_string(intinput2) + "?\nY: yes  N: no\n";
                    std::cin >> inputchar;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        if (std::tolower(inputchar) == 'y') {
                            gen.erase(gen.begin() + intinput2);
                            SaveGender(gen, genfile);
                            ReadGender(gen, genfile);
                            TableOutputGender(gen, outputsize, border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                        if (std::tolower(inputchar) == 'n') {
                            Clear();
                            TableOutputGender(gen, outputsize, border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                    }
                } while (true);
            }
        } while (true);
        break;
    case 7:
        TableOutputReason(reason, outputsize, border);
        MenuRemoveObjectsNextText(outputsize, 5);
        do {
            intinput2 = 0;
            std::cout << "Enter your choice: ";
            std::cin >> intinput2;
            if ((std::cin.fail()) or (intinput2 < -1) or (intinput2 >=
                static_cast<int>(reason.size()))) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                std::cout << "invalid input, try again\n";
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (intinput2 == -1) {
                    break;
                }
                do {
                    std::cout << "Confirm deletion of object *"
                        + std::to_string(intinput2) + "?\nY: yes  N: no\n";
                    std::cin >> inputchar;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                    }
                    else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::
                            max(), '\n');
                        if (std::tolower(inputchar) == 'y') {
                            reason.erase(reason.begin() + intinput2);
                            SaveReason(reason, reasonfile);
                            ReadReason(reason, reasonfile);
                            TableOutputReason(reason, outputsize, border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                        if (std::tolower(inputchar) == 'n') {
                            Clear();
                            TableOutputReason(reason, outputsize, border);
                            MenuRemoveObjectsNextText(outputsize, 5);
                            break;
                        }
                    }
                } while (true);
            }
        } while (true);
        break;
    }
}

void MenuRemoveObjectsText(int& outputsize) {

    std::string text;
    text = "Choose an object to remove.\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "1: Owner\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "2: Animal\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "3: Appointment\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "4: Species\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "5: Specie Breed\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "6: Animal Gender\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "7: Appointment Reason\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "8: Return\n";
    Outputconverter(text, outputsize);
    std::cout << text;
}

void MenuRemoveObjects(int& outputsize, char& border,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile) {

    MenuAddObjectsText(outputsize);
    short int choice;
    do {
        choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            Clear();
            if (owner.empty()) {
                std::cout << "No data for Owner found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 2:
            Clear();
            if (animal.empty()) {
                std::cout << "No data for Animal found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 3:
            Clear();
            if (app.empty()) {
                std::cout << "No data for Appointment found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 4:
            Clear();
            if (spec.empty()) {
                std::cout << "No data for Species found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 5:
            Clear();
            if (charac.empty()) {
                std::cout << "No data for Specie Breed found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 6:
            Clear();
            if (gen.empty()) {
                std::cout << "No data for Animal Gender found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 7:
            Clear();
            if (reason.empty()) {
                std::cout << "No data for Appointment Reason found, add it"
                    " first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuRemoveObjectsNext(outputsize, border, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuRemoveObjectsText(outputsize);
            break;
        case 8:
            break;
        default: std::cout << "invalid input, try again\n"; break;
        }
    } while (choice != 8);
}

void MenuEditObjectsNextText(int& outputsize, const short int choice) {

    std::string text;
    switch (choice) {
    case 1:
        text = "Select an Owner data edit.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Full Name\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 2:
        text = "Select an Animal data edit.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Name\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Specie\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Specie Breed\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Animal Gender\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Years of Age\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Weight\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "8: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "9: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;

    case 3:
        text = "Select an Appointment data edit.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Appointment ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Owner ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Animal ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Date\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Appointment Reason\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "6: Commentary\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "7: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 4:
        text = "Choose an object to edit by writing a number after the"
            " \"*\". Write \"-1\" to return.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 5:
        text = "Select how to edit Owner ID.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Change Owner ID in Owner\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Change Owner ID in Owner and all animals tied to its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Change Owner ID in Owner and all appointments tied to"
            " its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "4: Change Owner ID in Owner and all animals and appointments"
            " tied to its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "5: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 6:
        text = "Select how to edit Animal ID.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Change Animal ID in Animal\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Change Animal ID in Animal and all appointments tied"
            " to its ID\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    case 7:
        text = "Select data to edit in Specie Breed.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "Menu:\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "1: Specie\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "2: Breed\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        text = "3: Return\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        break;
    }
}

void MenuEditOwner(int& outputsize, const int b, const int i,
    std::vector<Owner>& owner, std::string& ownerfile,
    std::vector<Animal>& animal, std::string& animalfile,
    std::vector<Appointment>& app, std::string& appfile) {
    //b: 1 - owner id  2 - full name
    /*if b == 1, i: 1 - none  2 - +animal  3 - +appointment  4 - +animal and
    appointment*/

    long int inputint;
    unsigned int oldid;
    unsigned int newid;
    bool check;
    bool check2;
    std::string text;
    std::string inputstr;
    char inputchar;
    size_t n;

    text = "Write an Owner ID for which you want to edit data. "
        "Write \"-1\" to return.\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    do {
        std::cout << "Owner ID: ";
        std::cin >> inputint;
        if ((std::cin.fail()) or (inputint < -1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input, try again\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (inputint == -1) {
                return;
            }
            check = false;
            n = 0;
            oldid = static_cast<unsigned int>(inputint);
            while (n < owner.size()) {
                if (owner[n].owner_id == oldid) {
                    check = true;
                    break;
                }
                else {
                    n++;
                }
            }
            if (check) {
                break;
            }
            else {
                text = "No data with this Owner ID found\n";
                Outputconverter(text, outputsize);
                std::cout << text;
            }
        }
    } while (true);
    if (b == 1) {
        oldid = owner[n].owner_id;
        do {
            text = "Write a natural non negative number for new Owner ID: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> newid;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                check = true;
                for (auto& o : owner) {
                    if (o.owner_id == newid) {
                        text = "Owner ID must be unique\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    owner[n].owner_id = newid;
                    break;
                }
            }
        } while (true);
        Clear();
        if (i == 2) {
            for (auto& a : animal) {
                if (a.owner_id == oldid) {
                    a.owner_id = owner[n].owner_id;
                }
            }
            SaveAnimal(animal, animalfile);
        }
        if (i == 3) {
            for (auto& a : app) {
                if (a.owner_id == oldid) {
                    a.owner_id = owner[n].owner_id;
                }
            }
            SaveAppointment(app, appfile);
        }
        if (i == 4) {
            for (auto& a : animal) {
                if (a.owner_id == oldid) {
                    a.owner_id = owner[n].owner_id;
                }
            }
            SaveAnimal(animal, animalfile);
            for (auto& a : app) {
                if (a.owner_id == oldid) {
                    a.owner_id = owner[n].owner_id;
                }
            }
            SaveAppointment(app, appfile);
        }
        SaveOwner(owner, ownerfile);
        ReadOwner(owner, ownerfile);
    }
    if (b == 2) {
        check = true;
        do {
            check2 = true;
            text = "Current Full Name is " + std::string(owner[n].full_name);
            Outputconverter(text, outputsize);
            std::cout << text;
            text = "\nWrite a string of 80 characters maximum for new Full "
                "Name\n";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::getline(std::cin, inputstr);
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                inputstr = Removespaces(inputstr);
                if (!(inputstr.empty())) {
                    if (inputstr.size() > 80) {
                        do {
                            text = "Your text is more than 80 characters, do "
                                " you want to crop it?";
                            Outputconverter(text, outputsize);
                            text = text + "\nY: yes  N: no\n";
                            std::cout << text;
                            std::cin >> inputchar;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::
                                    streamsize>::max(), '\n');
                            }
                            else {
                                std::cin.ignore(std::numeric_limits<std::
                                    streamsize>::max(), '\n');
                                if (std::tolower(inputchar) == 'y') {
                                    StringBounder(inputstr, 80);
                                    check2 = false;
                                    break;
                                }
                                if (std::tolower(inputchar) == 'n') {
                                    check2 = false;
                                    inputstr = "";
                                    break;
                                }
                            }
                        } while (true);
                        if (!(inputstr.empty())) {
                            strcpy_s(owner[n].full_name, inputstr.c_str());
                            break;
                        }
                    }
                    else {
                        strcpy_s(owner[n].full_name, inputstr.c_str());
                        break;
                    }
                }
            }
        } while (check2);
        SaveOwner(owner, ownerfile);
    }
}

void MenuEditAnimal(int& outputsize, const int b, const int i,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::vector<Characteristics>& charac,
 std::vector<Gender>& gen) {
    /*b: 1 - animal id  2 - name  3 - specie  4 - breed  5 - gender  6 - age
    7 - weight  8 - owner id*/
    //b == 1, i: 1 - none  2 - +appointment
    std::string text;
    std::string inputstr1;
    unsigned int inputint;
    long int inputlongint;
    unsigned short int inputshortint;
    unsigned int oldid;
    unsigned int newid;
    char inputchar;
    float inputfloat;
    size_t n;
    bool check = true;

    text = "Write an Animal ID for which you want to edit data. "
        "Write \"-1\" to return.\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    do {
        std::cout << "Animal ID: ";
        std::cin >> inputlongint;
        if ((std::cin.fail()) or (inputlongint < -1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input, try again\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (inputlongint == -1) {
                return;
            }
            check = false;
            n = 0;
            oldid = static_cast<unsigned int>(inputlongint);
            while (n < animal.size()) {
                if (animal[n].animal_id == oldid) {
                    check = true;
                    break;
                }
                else {
                    n++;
                }
            }
            if (check) {
                break;
            }
            else {
                text = "No data with this Animal ID found\n";
                Outputconverter(text, outputsize);
                std::cout << text;
            }
        }
    } while (true);
    if (b == 1) {
        oldid = animal[n].animal_id;
        do {
            text = "Write a natural non negative number for new Animal ID: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> newid;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                check = true;
                for (auto& a : animal) {
                    if (a.animal_id == newid) {
                        text = "Animal ID must be unique\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    animal[n].animal_id = newid;
                    break;
                }
            }
        } while (true);
        Clear();
        if (i == 2) {
            for (auto& a : app) {
                if (a.animal_id == oldid) {
                    a.animal_id = animal[n].animal_id;
                }
            }
            SaveAppointment(app, appfile);
        }
        SaveAnimal(animal, animalfile);
        ReadAnimal(animal, animalfile);
    }
    if (b == 2) {
        do {
            text = "Current Name is " + std::string(animal[n].name);
            Outputconverter(text, outputsize);
            std::cout << text;
            text = "\nWrite a string of 60 characters maximum for new Name\n";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::getline(std::cin, inputstr1);
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                inputstr1 = Removespaces(inputstr1);
                if (!(inputstr1.empty())) {
                    if (inputstr1.size() > 60) {
                        do {
                            text = "Your text is more than 60 characters, do "
                                "you want to crop it?";
                            Outputconverter(text, outputsize);
                            text = text + "\nY: yes  N: no\n";
                            std::cout << text;
                            std::cin >> inputchar;
                            if (std::cin.fail()) {	//clear input if it was bad
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::
                                    streamsize>::max(), '\n');
                            }
                            else {
                                std::cin.ignore(std::numeric_limits<std::
                                    streamsize>::max(), '\n');
                                if (std::tolower(inputchar) == 'y') {
                                    StringBounder(inputstr1, 60);
                                    break;
                                }
                                if (std::tolower(inputchar) == 'n') {
                                    inputstr1 = "";
                                    break;
                                }
                            }
                        } while (true);
                        if (!(inputstr1.empty())) {
                            strcpy_s(animal[n].name, inputstr1.c_str());
                            break;
                        }
                    }
                    else {
                        strcpy_s(animal[n].name, inputstr1.c_str());
                        break;
                    }
                }
            }
        } while (true);
        SaveAnimal(animal, animalfile);
    }

    if (b == 3) {
        TableOutputSpecies(spec, outputsize);
        do {
            text = "Choose an object by writing a number after the \"*\". You "
             "can add more objects from the menu of the respective object.\n";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputint < spec.size()) {
                    animal[n].characteristics.species = spec[inputint];
                    break;
                }
            }
        } while (true);
        SaveAnimal(animal, animalfile);
    }

    if (b == 4) {
        TableOutputCharacteristics(charac, outputsize);
        do {
            text = "Choose an object by writing a number after the \"*\". You "
             "can add more objects from the menu of the respective object.\n";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputint < charac.size()) {
                    animal[n].characteristics = charac[inputint];
                    break;
                }
            }
        } while (true);
        SaveAnimal(animal, animalfile);
    }

    if (b == 5) {
        TableOutputGender(gen, outputsize);
        do {
            text = "Choose an object by writing a number after the \"*\". You "
             "can add more objects from the menu of the respective object.\n";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                if (inputint < gen.size()) {
                    animal[n].gender = gen[inputint];
                    break;
                }
            }
        } while (true);
        SaveAnimal(animal, animalfile);
    }

    if (b == 6) {
        do {
            text = "Write a natural non negative number for Years of Age: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputshortint;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                animal[n].age = inputshortint;
                break;
            }
        } while (true);
        SaveAnimal(animal, animalfile);
    }

    if (b == 7) {
        do {
            text = "Write a real positive number for Weight: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputfloat;
            if ((std::cin.fail()) or (inputfloat <= 0)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                animal[n].weight = inputfloat;
                break;
            }
        } while (true);
        SaveAnimal(animal, animalfile);
    }

    if (b == 8) {
        do {
            text = "Write a natural non negative number for Owner ID: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                animal[n].owner_id = inputint;
                break;
            }
        } while (true);
        SaveAnimal(animal, animalfile);
        UpdateNoAOwner(ownerfile, animalfile);
        ReadOwner(owner, ownerfile);
    }
}

void MenuEditAppointment(int& outputsize, const int b,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Reason>& reason) {

    std::string text;
    std::string inputstr1;
    unsigned int inputint;
    unsigned int oldid;
    unsigned int newid;
    long int inputlongint;
    char inputchar;
    bool check = true;
    size_t n;

    text = "Write an Appointment ID for which you want to edit data. "
        "Write \"-1\" to return.\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    do {
        std::cout << "Appointment ID: ";
        std::cin >> inputlongint;
        if ((std::cin.fail()) or (inputlongint < -1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input, try again\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (inputlongint == -1) {
                return;
            }
            check = false;
            n = 0;
            oldid = static_cast<unsigned int>(inputlongint);
            while (n < app.size()) {
                if (app[n].appointment_id == oldid) {
                    check = true;
                    break;
                }
                else {
                    n++;
                }
            }
            if (check) {
                break;
            }
            else {
                text = "No data with this Appointment ID found\n";
                Outputconverter(text, outputsize);
                std::cout << text;
            }
        }
    } while (true);

    if (b == 1) {
        do {
            text = "Write a natural non negative number for new Appointment "
                "ID: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> newid;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                check = true;
                for (auto& a : app) {
                    if (a.appointment_id == newid) {
                        text = "Appointment ID must be unique\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    app[n].appointment_id = newid;
                    break;
                }
            }
        } while (true);
        Clear();
        SaveAppointment(app, appfile);
        ReadAppointment(app, appfile);
    }
    if (b == 2) {
        do {
            text = "Write a natural non negative number for new Owner ID: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> newid;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                app[n].owner_id = newid;
            }
        } while (true);
        Clear();
        SaveAppointment(app, appfile);
    }

    if (b == 3) {
        do {
            text = "Write a natural non negative number for new Animal ID: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> newid;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                app[n].animal_id = newid;
            }
        } while (true);
        Clear();
        SaveAppointment(app, appfile);
    }

    if (b == 4) {
        text = "Write date and time in the folowing format: Day.Month.Year "
            "Hour:Minute. Year cannot be less than 1900.\n\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        app[n].date = InputDate();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Clear();
        SaveAppointment(app, appfile);
    }

    if (b == 5) {
        TableOutputReason(reason, outputsize);
        do {
            text = "Choose an object by writing a number after the \"*\". You "
             "can add more objects from the menu of the respective object.\n";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputint < reason.size()) {
                    app[n].reason = reason[inputint];
                    break;
                }
            }
        } while (true);
        Clear();
        SaveAppointment(app, appfile);
    }

    if (b == 6) {
        do {
            text = "Write a string of 160 characters maximum for Commentary: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::getline(std::cin, inputstr1);
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                inputstr1 = Removespaces(inputstr1);
                if (!(inputstr1.empty())) {
                    if (inputstr1.size() > 160) {
                        do {
                            text = "Your text is more than 160 characters, do "
                                "you want to crop it?";
                            Outputconverter(text, outputsize);
                            text = text + "\nY: yes  N: no\n";
                            std::cout << text;
                            std::cin >> inputchar;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::
                                    streamsize>::max(), '\n');
                            }
                            else {
                                std::cin.ignore(std::numeric_limits<std::
                                    streamsize>::max(), '\n');
                                if (std::tolower(inputchar) == 'y') {
                                    StringBounder(inputstr1, 160);
                                    break;
                                }
                                if (std::tolower(inputchar) == 'n') {
                                    inputstr1 = "";
                                    break;
                                }
                            }
                        } while (true);
                        if (!(inputstr1.empty())) {
                            strcpy_s(app[n].commentary, inputstr1.c_str());
                            break;
                        }
                    }
                    else {
                        strcpy_s(app[n].commentary, inputstr1.c_str());
                        break;
                    }
                }
            }
        } while (true);
        Clear();
        SaveAppointment(app, appfile);
    }
}

void MenuEditCharacteristics(int& outputsize, const int b,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Species>& spec, std::vector<Animal>& animal,
 std::string& animalfile) {
    //b: 1 - species  2 - breed

    std::string text;
    std::string inputstr1;
    long int inputlongint;
    char inputchar;
    bool check = true;
    size_t n;
    Characteristics newcharac;

    if (b == 1) {
        TableOutputCharacteristics(charac, outputsize);
        MenuEditObjectsNextText(outputsize, 4);
        do {
            text = "Enter your choice: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputlongint;
            if ((std::cin.fail()) or (inputlongint < -1)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputlongint == -1) {
                    return;
                }
                if (inputlongint < static_cast<long>(charac.size())) {
                    inputstr1 = charac[static_cast<unsigned __int64>
                     (inputlongint)].species.species;
                    newcharac = charac[static_cast<unsigned __int64>
                        (inputlongint)];
                    n = static_cast<size_t>(inputlongint);
                    Clear();
                    TableOutputSpecies(spec, outputsize);
                    text = "Choose an object to replace with by writing a "
                     "number after the \"*\". You can add more objects in the "
                     "respective menu. Write \"-1\" to return.\n\n";
                    Outputconverter(text, outputsize);
                    std::cout << text;
                    do {
                        text = "Enter your choice: ";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        std::cin >> inputlongint;
                        if ((std::cin.fail()) or (inputlongint < -1)) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                            if (inputlongint == -1) {
                                Clear();
                                TableOutputCharacteristics(charac, outputsize);
                                MenuEditObjectsNextText(outputsize, 4);
                                break;
                            }
                            if (inputlongint < static_cast<long>(spec.size())){
                                newcharac.species = spec[static_cast
                                 <unsigned __int64>(inputlongint)];
                                check = true;

                                for (auto& c : charac) {
                                    if ((Removespaces(c.species.species) ==
                                     Removespaces(newcharac.species.species))
                                     and (Removespaces(c.breed)
                                     == Removespaces(newcharac.breed))) {
                                        text = "Combination of Specie Breed "
                                            "must be unique";
                                        Outputconverter(text, outputsize);
                                        std::cout << text;
                                        check = false;
                                        break;
                                    }
                                }
                                if (check) {
                                    for (auto& a : animal) {
                                        if ((Removespaces(a.characteristics.
                                         species.species) == Removespaces(
                                         charac[static_cast<unsigned __int64>
                                         (n)].species.species)) and
                                         (Removespaces(a.characteristics.breed)
                                         == Removespaces(charac[static_cast
                                         <unsigned __int64>(n)].breed))) {
                                            strcpy_s(a.characteristics.species.
                                             species, newcharac.species.
                                             species);
                                        }
                                    }
                                    SaveAnimal(animal, animalfile);
                                    ReadAnimal(animal, animalfile);
                                    charac[n] = newcharac;
                                    SaveCharacteristics(charac, characfile);
                                    ReadCharacteristics(charac, characfile);
                                    return;
                                }
                            }
                        }
                    } while (true);
                }
            }
        } while (true);
    }

    if (b == 2) {
        TableOutputCharacteristics(charac, outputsize);
        MenuEditObjectsNextText(outputsize, 4);
        do {
            text = "Enter your choice: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputlongint;
            if ((std::cin.fail()) or (inputlongint < -1)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputlongint == -1) {
                    return;
                }
                if (inputlongint < static_cast<long>(charac.size())) {
                    inputstr1 = charac[static_cast<unsigned __int64>
                     (inputlongint)].breed;
                    newcharac = charac[static_cast<unsigned __int64>
                     (inputlongint)];
                    n = static_cast<size_t>(inputlongint);
                    Clear();
                    std::cout << text;
                    do {
                        text = "Current Breed is " + std::string(charac[n].
                            breed);
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        text = "\nWrite a string of 60 characters maximum for "
                            "new Breed\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        std::getline(std::cin, inputstr1);
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            inputstr1 = Removespaces(inputstr1);
                            if (!(inputstr1.empty())) {
                                if (inputstr1.size() > 60) {
                                    do {
                                        text = "Your text is more than 60 "
                                         "characters, do you want to crop it?";
                                        Outputconverter(text, outputsize);
                                        text = text + "\nY: yes  N: no\n";
                                        std::cout << text;
                                        std::cin >> inputchar;
                                        if (std::cin.fail()) {
                                            std::cin.clear();
                                            std::cin.ignore(std::
                                             numeric_limits<std::streamsize>::
                                             max(), '\n');
                                        }
                                        else {
                                            std::cin.ignore(std::numeric_limits
                                             <std::streamsize>::max(), '\n');
                                            if (std::tolower(inputchar) == 'y')
                                            {
                                                StringBounder(inputstr1, 60);
                                                break;
                                            }
                                            if (std::tolower(inputchar) == 'n')
                                            {
                                                inputstr1 = "";
                                                break;
                                            }
                                        }
                                    } while (true);
                                }
                                else {
                                    strcpy_s(newcharac.breed, inputstr1.c_str()
                                    );
                                }
                            }
                            if (!(inputstr1.empty())) {

                                strcpy_s(newcharac.breed, inputstr1.c_str());
                                check = true;
                                for (auto& c : charac) {
                                    if ((Removespaces(c.species.species) ==
                                     Removespaces(newcharac.species.species))
                                     and (Removespaces(c.breed)
                                     == Removespaces(newcharac.breed))) {
                                        text = "Combination of Specie Breed "
                                            "must be unique";
                                        Outputconverter(text, outputsize);
                                        std::cout << text;
                                        check = false;
                                        break;
                                    }
                                }
                                if (check) {
                                    for (auto& a : animal) {
                                        if ((Removespaces(a.characteristics.
                                         species.species) == Removespaces(
                                         charac[static_cast<unsigned __int64>
                                         (n)].species.species)) and
                                         (Removespaces(a.characteristics.breed)
                                         == Removespaces(charac[static_cast
                                         <unsigned __int64>(n)].breed))) {
                                            strcpy_s(a.characteristics.breed,
                                            newcharac.breed);
                                        }
                                    }
                                    SaveAnimal(animal, animalfile);
                                    ReadAnimal(animal, animalfile);
                                    charac[n] = newcharac;
                                    SaveCharacteristics(charac, characfile);
                                    ReadCharacteristics(charac, characfile);
                                    return;
                                }
                                break;
                            }

                        }
                    } while (true);
                }
            }
        } while (true);
    }
}

void MenuEditObjectsNext(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile) {

    short int choice;
    short int choice2;
    long int inputint = -2;
    bool check;
    bool check2;
    std::string text;
    std::string inputstr;
    char inputchar;
    switch (oldchoice) {
    case 1:
        MenuEditObjectsNextText(outputsize, oldchoice);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuEditObjectsNextText(outputsize, 5);
                do {
                    choice2 = 0;
                    std::cout << "Enter your choice: ";
                    std::cin >> choice2;
                    if (std::cin.fail()) {	//clear input if it was bad
                        std::cin.clear();
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::
                        max(), '\n');
                    switch (choice2) {
                    case 1:
                        Clear();
                        MenuEditOwner(outputsize, 1, choice2, owner,
                            ownerfile, animal, animalfile, app, appfile);
                        Clear();
                        MenuEditObjectsNextText(outputsize, 5);
                        break;
                    case 2:
                        Clear();
                        MenuEditOwner(outputsize, 1, choice2, owner,
                            ownerfile, animal, animalfile, app, appfile);
                        Clear();
                        MenuEditObjectsNextText(outputsize, 5);
                        break;
                    case 3:
                        Clear();
                        MenuEditOwner(outputsize, 1, choice2, owner,
                            ownerfile, animal, animalfile, app, appfile);
                        Clear();
                        MenuEditObjectsNextText(outputsize, 5);
                        break;
                    case 4:
                        Clear();
                        MenuEditOwner(outputsize, 1, choice2, owner,
                            ownerfile, animal, animalfile, app, appfile);
                        Clear();
                        MenuEditObjectsNextText(outputsize, 5);
                        break;
                    case 5:
                        break;
                    default: std::cout << "invalid input, try again\n"; break;
                    }
                } while (choice2 != 5);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuEditOwner(outputsize, 2, 1, owner, ownerfile,
                    animal, animalfile, app, appfile);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 2:
        MenuEditObjectsNextText(outputsize, oldchoice);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuEditObjectsNextText(outputsize, 6);
                do {
                    choice2 = 0;
                    std::cout << "Enter your choice: ";
                    std::cin >> choice2;
                    if (std::cin.fail()) {	//clear input if it was bad
                        std::cin.clear();
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::
                        max(), '\n');
                    switch (choice2) {
                    case 1:
                        Clear();
                        MenuEditAnimal(outputsize, choice, choice2,
                            owner, ownerfile, animal, animalfile, app, appfile,
                            spec, charac, gen);
                        Clear();
                        MenuEditObjectsNextText(outputsize, 6);
                        break;
                    case 2:
                        Clear();
                        MenuEditAnimal(outputsize, choice, choice2,
                            owner, ownerfile, animal, animalfile, app, appfile,
                            spec, charac, gen);
                        Clear();
                        MenuEditObjectsNextText(outputsize, 6);
                        break;
                    case 3:
                        break;
                    default: std::cout << "invalid input, try again\n"; break;
                    }
                } while (choice2 != 3);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 6:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 7:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 8:
                Clear();
                MenuEditAnimal(outputsize, choice, 1, owner,
                    ownerfile, animal, animalfile, app, appfile, spec, charac,
                    gen);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 9:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 9);
        break;
    case 3:
        MenuEditObjectsNextText(outputsize, oldchoice);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuEditAppointment(outputsize, choice, app, appfile,
                    reason);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 2:
                Clear();
                MenuEditAppointment(outputsize, choice, app, appfile,
                    reason);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 3:
                Clear();
                MenuEditAppointment(outputsize, choice, app, appfile,
                    reason);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 4:
                Clear();
                MenuEditAppointment(outputsize, choice, app, appfile,
                    reason);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 5:
                Clear();
                MenuEditAppointment(outputsize, choice, app, appfile,
                    reason);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 6:
                Clear();
                MenuEditAppointment(outputsize, choice, app, appfile,
                    reason);
                Clear();
                MenuEditObjectsNextText(outputsize, oldchoice);
                break;
            case 7:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 7);
        break;
    case 4:
        TableOutputSpecies(spec, outputsize);
        MenuEditObjectsNextText(outputsize, 4);
        text = "Attention! This will replace existing occurrences in all "
            "data.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        check2 = false;
        do {
            if (check2 == true) {
                check = true;
                for (auto& s : spec) {
                    if (s.species == inputstr) {
                        Clear();
                        TableOutputSpecies(spec, outputsize);
                        MenuEditObjectsNextText(outputsize, 4);
                        text = "Attention! This will replace existing "
                            "occurrences in all data.\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        text = "Specie must be unique\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (auto& c : charac) {
                        if (Removespaces(c.species.species) ==
                            Removespaces(spec[static_cast<unsigned
                                __int64>(inputint)].species)) {
                            strcpy_s(c.species.species,
                                inputstr.c_str());
                        }
                    }
                    SaveCharacteristics(charac, characfile);
                    ReadCharacteristics(charac, characfile);
                    for (auto& a : animal) {
                        if (Removespaces(a.characteristics.species.
                            species) == Removespaces(spec[static_cast
                                <unsigned __int64>(inputint)].
                                species)) {
                            strcpy_s(a.characteristics.species.
                                species, inputstr.c_str());
                        }
                    }
                    SaveAnimal(animal, animalfile);
                    ReadAnimal(animal, animalfile);
                    strcpy_s(spec[static_cast<unsigned __int64>
                        (inputint)].species, inputstr.c_str());
                    SaveSpecies(spec, specfile);
                    ReadSpecies(spec, specfile);
                    strcpy_s(spec[static_cast<unsigned __int64>
                        (inputint)].species, inputstr.c_str());
                    break;
                }
            }
            check2 = false;
            text = "Enter your choice: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if ((std::cin.fail()) or (inputint < -1)) {
                std::cout << (std::cin.fail());
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputint == -1) {
                    break;
                }
                if (inputint < static_cast<long>(spec.size())) {
                    do {
                        text = "Write a string of 60 characters maximum for "
                            "new Specie: ";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        std::getline(std::cin, inputstr);
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            inputstr = Removespaces(inputstr);
                            if (!(inputstr.empty())) {
                                if (inputstr.size() > 60) {
                                    do {
                                        text = "Your text is more than 60 "
                                         "characters, do you want to crop it?";
                                        Outputconverter(text, outputsize);
                                        text = text + "\nY: yes  N: no\n";
                                        std::cout << text;
                                        std::cin >> inputchar;
                                        if (std::cin.fail()) {
                                            std::cin.clear();
                                            std::cin.ignore(std::
                                             numeric_limits<std::streamsize>::
                                             max(), '\n');
                                        }
                                        else {
                                            std::cin.ignore(std::numeric_limits
                                             <std::streamsize>::max(), '\n');
                                            if (std::tolower(inputchar)
                                                == 'y') {
                                                StringBounder(inputstr, 60);
                                                break;
                                            }
                                            if (std::tolower(inputchar)
                                                == 'n') {
                                                inputstr = "";
                                                break;
                                            }
                                        }
                                    } while (true);
                                    if (!(inputstr.empty())) {
                                        check2 = true;
                                        break;
                                    }
                                }
                                else {
                                    check2 = true;
                                    break;
                                }
                            }
                            else {
                                for (auto& c : charac) {
                                    if (Removespaces(c.species.species) ==
                                        Removespaces(spec[static_cast<unsigned 
                                         __int64>(inputint)].species)) {
                                        strcpy_s(c.species.species,
                                            inputstr.c_str());
                                    }
                                }
                                SaveCharacteristics(charac, characfile);
                                ReadCharacteristics(charac, characfile);
                                for (auto& a : animal) {
                                    if (Removespaces(a.characteristics.species.
                                     species) == Removespaces(spec[static_cast
                                      <unsigned __int64>(inputint)].
                                     species)) {
                                        strcpy_s(a.characteristics.species.
                                            species, inputstr.c_str());
                                    }
                                }
                                SaveAnimal(animal, animalfile);
                                ReadAnimal(animal, animalfile);
                                strcpy_s(spec[static_cast<unsigned __int64>
                                 (inputint)].species, inputstr.c_str());
                                SaveSpecies(spec, specfile);
                                ReadSpecies(spec, specfile);
                                break;
                            }
                        }
                    } while (true);
                }

            }
        } while (true);
        SaveSpecies(spec, specfile);
        ReadSpecies(spec, specfile);
        break;
    case 5:
        MenuEditObjectsNextText(outputsize, 7);
        do {
            choice = 0;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {	//clear input if it was bad
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choice) {
            case 1:
                Clear();
                MenuEditCharacteristics(outputsize, choice, charac,
                    characfile, spec, animal, animalfile);
                Clear();
                MenuEditObjectsNextText(outputsize, 7);
                break;
            case 2:
                Clear();
                MenuEditCharacteristics(outputsize, choice, charac,
                    characfile, spec, animal, animalfile);
                Clear();
                MenuEditObjectsNextText(outputsize, 7);
                break;
            case 3:
                break;
            default: std::cout << "invalid input, try again\n"; break;
            }
        } while (choice != 3);
        break;
    case 6:
        TableOutputGender(gen, outputsize);
        MenuEditObjectsNextText(outputsize, 4);
        text = "Attention! This will replace existing occurrences in all "
            "data.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        check2 = false;
        do {
            if (check2 == true) {
                check = true;
                for (auto& g : gen) {
                    if (Removespaces(g.gender) == inputstr) {
                        Clear();
                        TableOutputGender(gen, outputsize);
                        MenuEditObjectsNextText(outputsize, 4);
                        text = "Attention! This will not replace existing "
                            "occurrences in all data.\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        text = "Gender must be unique\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (auto& a : animal) {
                        if (Removespaces(a.gender.gender) ==
                            Removespaces(gen[static_cast<unsigned
                                __int64>(inputint)].gender)) {
                            strcpy_s(gen[static_cast<unsigned
                                __int64>(inputint)].gender, inputstr
                                .c_str());
                        }
                    }
                    SaveAnimal(animal, animalfile);
                    ReadAnimal(animal, animalfile);
                    strcpy_s(gen[static_cast<unsigned __int64>
                        (inputint)].gender, inputstr.c_str());
                    SaveGender(gen, genfile);
                    ReadGender(gen, genfile);
                    strcpy_s(gen[static_cast<unsigned __int64>(inputint)]
                     .gender, inputstr.c_str());
                    break;
                }
            }
            check2 = false;
            text = "Enter your choice: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if ((std::cin.fail()) or (inputint < -1)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputint == -1) {
                    break;
                }
                if (inputint < static_cast<long>(spec.size())) {
                    do {
                        text = "Write a string of 60 characters maximum for "
                            "new Gender: ";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        std::getline(std::cin, inputstr);
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            inputstr = Removespaces(inputstr);
                            if (!(inputstr.empty())) {
                                if (inputstr.size() > 60) {
                                    do {
                                        text = "Your text is more than 60 "
                                         "characters, do you want to crop it?";
                                        Outputconverter(text, outputsize);
                                        text = text + "\nY: yes  N: no\n";
                                        std::cout << text;
                                        std::cin >> inputchar;
                                        if (std::cin.fail()) {
                                            std::cin.clear();
                                            std::cin.ignore(std::
                                             numeric_limits<std::streamsize>::
                                             max(), '\n');
                                        }
                                        else {
                                            std::cin.ignore(std::numeric_limits
                                             <std::streamsize>::max(), '\n');
                                            if (std::tolower(inputchar)
                                                == 'y') {
                                                StringBounder(inputstr, 60);
                                                break;
                                            }
                                            if (std::tolower(inputchar)
                                                == 'n') {
                                                inputstr = "";
                                                break;
                                            }
                                        }
                                    } while (true);
                                    if (!(inputstr.empty())) {
                                        check2 = true;
                                        break;
                                    }
                                }
                                else {
                                    check2 = true;
                                    break;
                                }
                            }
                            else {
                                for (auto& a : animal) {
                                    if (Removespaces(a.gender.gender) ==
                                     Removespaces(gen[static_cast<unsigned
                                     __int64>(inputint)].gender)) {
                                        strcpy_s(gen[static_cast<unsigned
                                         __int64>(inputint)].gender, inputstr
                                         .c_str());
                                    }
                                }
                                SaveAnimal(animal, animalfile);
                                ReadAnimal(animal, animalfile);
                                strcpy_s(gen[static_cast<unsigned __int64>
                                 (inputint)].gender, inputstr.c_str());
                                SaveGender(gen, genfile);
                                ReadGender(gen, genfile);
                                break;
                            }
                        }
                    } while (true);
                }
            }
        } while (true);
        SaveGender(gen, genfile);
        ReadGender(gen, genfile);
        break;
    case 7:
        TableOutputReason(reason, outputsize);
        MenuEditObjectsNextText(outputsize, 4);
        text = "Attention! This will replace existing occurrences in all "
            "data.\n";
        Outputconverter(text, outputsize);
        std::cout << text;
        check2 = false;
        do {
            if (check2 == true) {
                check = true;
                for (auto& r : reason) {
                    if (Removespaces(r.reason) == inputstr) {
                        Clear();
                        TableOutputReason(reason, outputsize);
                        MenuEditObjectsNextText(outputsize, 4);
                        text = "Attention! This will replace existing "
                            "occurrences in all data.\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        text = "Reason must be unique\n";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (auto& a : app) {
                        if (Removespaces(a.reason.reason) ==
                            Removespaces(reason[static_cast<unsigned
                                __int64>(inputint)].reason)) {
                            strcpy_s(reason[static_cast<unsigned
                                __int64>(inputint)].reason,
                                inputstr.c_str());
                        }
                    }
                    SaveAppointment(app, appfile);
                    ReadAppointment(app, appfile);
                    SaveReason(reason, reasonfile);
                    ReadReason(reason, reasonfile);
                    strcpy_s(reason[static_cast<unsigned __int64>(inputint)]
                     .reason, inputstr.c_str());
                    break;
                }
            }
            check2 = false;
            text = "Enter your choice: ";
            Outputconverter(text, outputsize);
            std::cout << text;
            std::cin >> inputint;
            if ((std::cin.fail()) or (inputint < -1)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n');
                if (inputint == -1) {
                    break;
                }
                if (inputint < static_cast<long>(spec.size())) {
                    do {
                        text = "Write a string of 80 characters maximum for "
                            "new Reason: ";
                        Outputconverter(text, outputsize);
                        std::cout << text;
                        std::getline(std::cin, inputstr);
                        if (std::cin.fail()) {	//clear input if it was bad
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::
                                streamsize>::max(), '\n');
                        }
                        else {
                            inputstr = Removespaces(inputstr);
                            if (!(inputstr.empty())) {
                                if (inputstr.size() > 80) {
                                    do {
                                        text = "Your text is more than 80 "
                                         "characters, do you want to crop it?";
                                        Outputconverter(text, outputsize);
                                        text = text + "\nY: yes  N: no\n";
                                        std::cout << text;
                                        std::cin >> inputchar;
                                        if (std::cin.fail()) {
                                            std::cin.clear();
                                            std::cin.ignore(std::
                                             numeric_limits<std::streamsize>::
                                             max(), '\n');
                                        }
                                        else {
                                            std::cin.ignore(std::numeric_limits
                                             <std::streamsize>::max(), '\n');
                                            if (std::tolower(inputchar)
                                                == 'y') {
                                                StringBounder(inputstr, 80);
                                                break;
                                            }
                                            if (std::tolower(inputchar)
                                                == 'n') {
                                                inputstr = "";
                                                break;
                                            }
                                        }
                                    } while (true);
                                    if (!(inputstr.empty())) {
                                        check2 = true;
                                        break;
                                    }
                                }
                                else {
                                    check2 = true;
                                    break;
                                }
                            }
                            else {
                                for (auto& a : app) {
                                    if (Removespaces(a.reason.reason) ==
                                     Removespaces(reason[static_cast<unsigned
                                     __int64>(inputint)].reason)) {
                                        strcpy_s(reason[static_cast<unsigned
                                         __int64>(inputint)].reason,
                                         inputstr.c_str());
                                    }
                                }
                                SaveAppointment(app, appfile);
                                ReadAppointment(app, appfile);
                                SaveReason(reason, reasonfile);
                                ReadReason(reason, reasonfile);
                                break;
                            }
                        }
                    } while (true);
                }
            }
        } while (true);
        SaveReason(reason, reasonfile);
        ReadReason(reason, reasonfile);
        break;
    }
}

void MenuEditObjectsText(int& outputsize) {

    std::string text;
    text = "Choose an object to edit.\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Attention! Editing Species, Specie Breed, Animal Gender or "
     "Appointment Reason will also change values in existing objects!\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "1: Owner\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "2: Animal\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "3: Appointment\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "4: Species\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "5: Specie Breed\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "6: Animal Gender\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "7: Appointment Reason\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "8: Return\n";
    Outputconverter(text, outputsize);
    std::cout << text;
}

void MenuEditObjects(int& outputsize, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile) {

    MenuEditObjectsText(outputsize);
    short int choice;
    std::string text;
    do {
        choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            Clear();
            if (owner.empty()) {
                std::cout << "No data for Owner found, add it first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 2:
            Clear();
            if ((animal.empty()) or (spec.empty()) or (charac.empty()) or
                (gen.empty())) {
                if (animal.empty()) {
                    std::cout << "No data for Animal found, add it first\n";
                }
                if (spec.empty()) {
                    std::cout << "No data for Species found, add it first\n";
                }
                if (charac.empty()) {
                    std::cout << "No data for Species Breed found, add it"
                        " first\n";
                }
                if (gen.empty()) {
                    std::cout << "No data for Animal Gender found, add it"
                        " first\n";
                }
                AnyKeyReturn(outputsize);
            }
            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 3:
            Clear();
            if ((app.empty()) or (reason.empty())) {
                if (app.empty()) {
                    std::cout << "No data for Appointment found, add it"
                        " first\n";
                }
                if (reason.empty()) {
                    std::cout << "No data for Appointment Reason found, add it"
                        " first\n";
                }
                AnyKeyReturn(outputsize);
            }
            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 4:
            Clear();
            if (spec.empty()) {
                std::cout << "No data for Species found, add it"
                    " first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 5:
            Clear();
            if ((spec.empty()) or (charac.empty())) {
                if (spec.empty()) {
                    std::cout << "No data for Species found, add it first\n";
                    AnyKeyReturn(outputsize);
                }
                if (charac.empty()) {
                    std::cout << "No data for Specie Breed found, add it"
                        " first\n";
                }
                AnyKeyReturn(outputsize);
            }

            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 6:
            Clear();
            if (gen.empty()) {
                std::cout << "No data for Animal Gender found, add it"
                    " first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 7:
            Clear();
            if (reason.empty()) {
                std::cout << "No data for Appointment Reason found, add it"
                    " first\n";
                AnyKeyReturn(outputsize);
            }
            else {
                MenuEditObjectsNext(outputsize, choice, animal,
                    animalfile, owner, ownerfile, app, appfile, spec, specfile,
                    charac, characfile, gen, genfile, reason, reasonfile);
            }
            Clear();
            MenuEditObjectsText(outputsize);
            break;
        case 8:
            break;
        default: std::cout << "invalid input, try again\n"; break;
        }
    } while (choice != 8);
}

void MenuText(int& outputsize) {
    std::string text;
    text = "Welcome to Vet Clinic database.\n\n";
    Outputconverter(text, outputsize); //making sure it works with custom
    //output size
    std::cout << text;
    text = "Menu:\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "1: Show data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "2: Add data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "3: Remove data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "4: Edit data\n";
    Outputconverter(text, outputsize);
    std::cout << text;
    text = "5: Exit program\n\n";
    Outputconverter(text, outputsize);
    std::cout << text;
}

void Menu(int& outputsize, char& border, std::string& specfile,
 std::string& characfile, std::string& genfile, std::string& animalfile,
 std::string& ownerfile, std::string& reasonfile, std::string& appfile) {

    std::vector<Species> origspec;
    std::vector<Characteristics> origchar;
    std::vector<Gender> origgen;
    std::vector<Animal> origanimal;
    std::vector<Owner> origowner;
    std::vector<Reason> origreason;
    std::vector<Appointment> origapp;

    MenuText(outputsize);
    FilesInitialise(origspec, specfile, origchar, characfile, origgen, genfile,
        origanimal, animalfile, origowner, ownerfile, origreason, reasonfile,
        origapp, appfile);

    short int choice;
    do {
        choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {	//clear input if it was bad
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            Clear();
            MenuShowObjects(outputsize, border, origspec, origchar,
                origgen, origanimal, origowner, origreason, origapp);
            Clear();
            MenuText(outputsize);
            break;
        case 2:
            Clear();
            MenuAddObjects(outputsize, border, origanimal, animalfile,
                origowner, ownerfile, origapp, appfile, origspec, specfile,
                origchar, characfile, origgen, genfile, origreason,
                reasonfile);
            Clear();
            MenuText(outputsize);
            break;
        case 3:
            Clear();
            MenuRemoveObjects(outputsize, border, origanimal, animalfile,
                origowner, ownerfile, origapp, appfile, origspec, specfile,
                origchar, characfile, origgen, genfile, origreason,
                reasonfile);
            Clear();
            MenuText(outputsize);
            break;
        case 4:
            Clear();
            MenuEditObjects(outputsize, origanimal, animalfile, origowner,
                ownerfile, origapp, appfile, origspec, specfile, origchar,
                characfile, origgen, genfile, origreason, reasonfile);
            Clear();
            MenuText(outputsize);
            break;
        case 5:
            break;
        default: std::cout << "invalid input, try again\n"; break;
        }
    } while (choice != 5);
}