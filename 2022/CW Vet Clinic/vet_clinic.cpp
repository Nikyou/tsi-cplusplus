#include "vet_clinic.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream> //for ofstream
#include <string>
#include <algorithm> //for sort

std::string Removespaces(std::string str) { //removes extra spaces at the end

    std::vector<char> strv(str.begin(), str.end());
    std::string newstr;
    if (strv.size() > 0) {
        for (auto i = strv.size() - 1; i > 1; i--)
            if (strv[i] == ' ') {
                strv.erase(strv.begin() + static_cast<__int64>(i));
            }
            else {
                break;
            }
    }
    newstr.clear();
    for (char c : strv) {
        newstr.push_back(c);
    }
    return newstr;
}

void Outputconverter(std::vector<char>& strv, int outputsize, unsigned int n,
 bool formating, char border, bool endc) { /*adds output formating and makes
    a line break if output is too long*/

    if (formating) {
        if (!(strv.size() < n * (outputsize + 1) - 1)) {
            unsigned int i = n * (outputsize + 1) - 3;
            for ( ; i > (n - 1) * (outputsize + 1); i--) {
                if (strv[i] == ' ') {
                    strv[i] = '\n';
                    strv.insert(strv.begin() + i, border);
                    if (!(i == n * (outputsize + 1) - 1)) {
                        for (unsigned int c = i; c < n * (outputsize + 1) - 2;
                            c++) {
                            strv.insert(strv.begin() + c, ' ');
                        }
                    }
                    strv.insert(strv.begin() + (n * (outputsize + 1)), ' ');
                    strv.insert(strv.begin() + (n * (outputsize + 1)), border);
                    // strv.push_back(border);
                    break;
                }
            }
            if (i == ((n - 1) * (outputsize + 1))) {
                strv.insert(strv.begin() + (n * (outputsize + 1) - 2), border);
                strv.insert(strv.begin() + (n * (outputsize + 1) - 1), '\n');
                strv.insert(strv.begin() + (n * (outputsize + 1)), ' ');
                strv.insert(strv.begin() + (n * (outputsize + 1)), border);
            }
            Outputconverter(strv, outputsize, n + 1, formating, border, endc);
        }
        else {
            if (endc) {
                strv.push_back(border);
                for (auto c = strv.size() - 1; c < n * (outputsize + 1) - 2;
                    c++) {
                    strv.insert(strv.begin() + static_cast<__int64>(c), ' ');
                }
                strv.push_back('\n');
            }
        }
    }
    else {
        if (!(strv.size() < n * (outputsize + 1) - 1)) {
            unsigned int i = n * (outputsize + 1) - 1;
            for ( ; (i > (n - 1) * (outputsize + 1)); i--) {
                if (strv[i] == ' ') {
                    strv[i] = '\n';
                    if (!(i + 1 == n * (outputsize + 1))) {
                        for (unsigned int c = i; c < n * (outputsize + 1) - 1; c++) {
                            strv.insert(strv.begin() + c, ' ');
                        }
                    }
                    break;
                }
            }
            if (i == ((n - 1) * (outputsize + 1))) {
                strv.insert(strv.begin() + (n * (outputsize + 1) - 1), '\n');
            }
            Outputconverter(strv, outputsize, n + 1, formating, border, endc);
        }
    }
}

void Outputconverter(std::string& str, int outputsize, unsigned int n,
 bool formating, char border, bool endc) {  /*adds output formating and makes
    a line break if output is too long*/

    std::vector<char> strv(str.begin(), str.end());
    if (formating) {
        if (!(strv.size() < n * (outputsize + 1) - 1)) {
            unsigned int i = n * (outputsize + 1) - 3;
            for ( ; i > (n - 1) * (outputsize + 1); i--) {
                if (strv[i] == ' ') {
                    strv[i] = '\n';
                    strv.insert(strv.begin() + i, border);
                    if (!(i == n * (outputsize + 1) - 1)) {
                        for (unsigned int c = i; c < n * (outputsize + 1) - 2; c++) {
                            strv.insert(strv.begin() + c, ' ');
                        }

                    }
                    strv.insert(strv.begin() + n * (outputsize + 1), ' ');
                    strv.insert(strv.begin() + n * (outputsize + 1), border);
                    // strv.push_back(border);
                    break;
                }
            }
            if (i == ((n - 1) * (outputsize + 1))) {
                strv.insert(strv.begin() + (n * (outputsize + 1) - 2), border);
                strv.insert(strv.begin() + (n * (outputsize + 1) - 1), '\n');
                strv.insert(strv.begin() + (n * (outputsize + 1)), ' ');
                strv.insert(strv.begin() + (n * (outputsize + 1)), border);
            }
            Outputconverter(strv, outputsize, n + 1, formating, border, endc);
        }
        else {
            if (endc) {
                strv.push_back(border);
                for (auto c = strv.size() - 1; c < n * (outputsize + 1) - 2; c++) {
                    strv.insert(strv.begin() + static_cast<__int64>(c), ' ');
                }
                strv.push_back('\n');
            }
        }
    }
    else {
        if (!(strv.size() < n * (outputsize + 1) - 1)) {
            unsigned int i = n * (outputsize + 1) - 1;
            for ( ; i > ((n - 1) * (outputsize + 1)); i--) {
                if (strv[i] == ' ') {
                    strv[i] = '\n';
                    if (!(i + 1 == n * (outputsize + 1))) {
                        for (unsigned int c = i; c < n * (outputsize + 1) - 1; c++) {
                            strv.insert(strv.begin() + c, ' ');
                        }
                    }
                    break;
                }
            }
            if (i == ((n - 1) * (outputsize + 1))) {
                strv.insert(strv.begin() + (n * (outputsize + 1) - 1), '\n');
            }
            Outputconverter(strv, outputsize, n + 1, formating, border, endc);
        }
    }
    str.clear();
    for (char c : strv) {
        str.push_back(c);
    }
}


bool CompareReasonasc(Reason& r1, Reason& r2) {
    return (strcmp(r1.reason, r2.reason) < 0);
}

void SaveReason(std::vector<Reason>& reason, std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(reason.empty())) {
            std::sort(reason.begin(), reason.end(), CompareReasonasc);
            for (auto& c : reason) {
                Reason* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write a reason file.\n";
    }
}

void ReadReason(std::vector<Reason>& reason, std::string& file) {

    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Reason>().swap(reason); //makes sure vector is empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Reason)];
            ifs.read(data, sizeof(Reason));
            Reason* pc = reinterpret_cast<Reason*>(data);
            reason.push_back(*pc);
        }
        if (!(reason.empty())) {
            std::sort(reason.begin(), reason.end(), CompareReasonasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else {
            std::cerr << "Failed to read a reason file.\n";
        }
    }
}

std::string StrTabOutputReason(Reason& reason, unsigned int& i, int& outputsize,
 char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }


     str = str + " " + Removespaces(reason.reason) + " ";
     if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
     }
     else {
        str = str + border;
     }

    if (str[str.size()-1] == border) {
        str[str.size()-1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size()-1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border,
            true);
    }

    return str;
}

std::string StrHeaderReason(int& outputsize, char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;
    
    str = str + " Reason ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border,
         true);
    }

    return str;
}

void TableOutputReason(std::vector<Reason>& reason, int& outputsize,
 char border) {


    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderReason(outputsize, border);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(reason.empty())) {
        for (unsigned int n = 0; n < reason.size(); n++) {
            std::cout << StrTabOutputReason(reason[n], n, outputsize, border);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}


bool CompareGenderasc(Gender& g1, Gender& g2) {
    return (strcmp(g1.gender, g2.gender) < 0);
}

void SaveGender(std::vector<Gender>& gender, std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(gender.empty())) {
            std::sort(gender.begin(), gender.end(), CompareGenderasc);
            for (auto& c : gender) {
                Gender* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write a gender file.\n";
    }
}

void ReadGender(std::vector<Gender>& gender, std::string& file) {

    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Gender>().swap(gender); //makes sure vector is empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Gender)];
            ifs.read(data, sizeof(Gender));
            Gender* pc = reinterpret_cast<Gender*>(data);
            gender.push_back(*pc);
        }
        if (!(gender.empty())) {
            std::sort(gender.begin(), gender.end(), CompareGenderasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else {
            std::cerr << "Failed to read a gender file.\n";
        }
    }
}

std::string StrTabOutputGender(Gender& gender,unsigned int& i, int& outputsize,
 char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    str = str + " " + Removespaces(gender.gender) + " ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border,
            true);
    }

    return str;
}

std::string StrHeaderGender(int& outputsize, char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;

    str = str + " Gender ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border,
         true);
    }

    return str;
}

void TableOutputGender(std::vector<Gender>& gender, int& outputsize,
 char border) {

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderGender(outputsize, border);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(gender.empty())) {
        for (unsigned int n = 0; n < gender.size(); n++) {
            std::cout << StrTabOutputGender(gender[n], n, outputsize, border);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}


bool CompareSpeciesasc(Species& s1, Species& s2) {
    return (strcmp(s1.species, s2.species) < 0);
}

void SaveSpecies(std::vector<Species>& species, std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(species.empty())) {
            std::sort(species.begin(), species.end(), CompareSpeciesasc);
            for (auto& c : species) {
                Species* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write a species file.\n";
    }
}

void ReadSpecies(std::vector<Species>& species, std::string& file) {

    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Species>().swap(species); //makes sure vector is empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Species)];
            ifs.read(data, sizeof(Species));
            Species* pc = reinterpret_cast<Species*>(data);
            species.push_back(*pc);
        }
        if (!(species.empty())) {
            std::sort(species.begin(), species.end(), CompareSpeciesasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else {
            std::cerr << "Failed to read a species file.\n";
        }
    }
}


std::string StrTabOutputSpecies(Species& species, unsigned int& i, int& outputsize,
 char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    str = str + " " + Removespaces(species.species) + " ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (str[str.size()-1] == border) {
        str[str.size()-1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size()-1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border,
            true);
    }

    return str;
}

std::string StrHeaderSpecies(int& outputsize, char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;

    str = str + " Specie ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true, border,
            true);
    }

    return str;
}

void TableOutputSpecies(std::vector<Species>& species, int& outputsize,
 char border) {

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderSpecies(outputsize, border);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(species.empty())) {
        for (unsigned int n = 0; n < species.size(); n++) {
            std::cout << StrTabOutputSpecies(species[n], n, outputsize,
             border);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}


bool CompareCharacteristicsbyspecasc(Characteristics& c1,
 Characteristics& c2) {
    return (strcmp(c1.species.species, c2.species.species) < 0);
}

bool CompareCharacteristicsbybreedasc(Characteristics& c1,
 Characteristics& c2) {
    return (strcmp(c1.breed, c2.breed) < 0);
}

void SaveCharacteristics(std::vector<Characteristics>& characteristics,
 std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(characteristics.empty())) {
            std::sort(characteristics.begin(), characteristics.end(),
             CompareCharacteristicsbybreedasc);
            std::sort(characteristics.begin(), characteristics.end(),
                CompareCharacteristicsbyspecasc);
            for (auto& c : characteristics) {
                Characteristics* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write a characteristics file.\n";
    }
}

void ReadCharacteristics(std::vector<Characteristics>& characteristics,
 std::string& file) {

    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Characteristics>().swap(characteristics); //makes sure 
         //vector is empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Characteristics)];
            ifs.read(data, sizeof(Characteristics));
            Characteristics* pc = reinterpret_cast<Characteristics*>(data);
            characteristics.push_back(*pc);
        }
        if (!(characteristics.empty())) {
            std::sort(characteristics.begin(), characteristics.end(),
             CompareCharacteristicsbybreedasc);
            std::sort(characteristics.begin(), characteristics.end(),
             CompareCharacteristicsbyspecasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else {
            std::cerr << "Failed to read a characteristics file.\n";
        }
    }
}

std::string StrTabOutputCharacteristics(Characteristics& characteristics,
 unsigned int& i, int& outputsize, char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    str = str + " " + Removespaces(characteristics.breed) + " ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    str = str + " " + Removespaces(characteristics.species.species) + " ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (str[str.size()-1] == border) {
        str[str.size()-1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size()-1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
        border, true);
    }

    return str;
}

std::string StrHeaderCharacteristics(int& outputsize, char& border) {

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;

    str = str + " Breed ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    str = str + " Specie ";
    if (str.size() > n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }


    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

void TableOutputCharacteristics(std::vector<Characteristics>& characteristics,
 int& outputsize, char border) {


    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderCharacteristics(outputsize, border);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(characteristics.empty())) {
        for (unsigned int n = 0; n < characteristics.size(); n++) {
            std::cout << StrTabOutputCharacteristics(characteristics[n], n,
             outputsize, border);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}


void SaveAnimal(std::vector<Animal>& animal, std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(animal.empty())) {
            std::sort(animal.begin(), animal.end(), CompareAnimalbyidasc);
            for (auto& c : animal) {
                Animal* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write an animal file.\n";
    }
}

void ReadAnimal(std::vector<Animal>& animal, std::string& file) {

    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Animal>().swap(animal); //makes sure vector is empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Animal)];
            ifs.read(data, sizeof(Animal));
            Animal* pc = reinterpret_cast<Animal*>(data);
            animal.push_back(*pc);
        }
        if (!(animal.empty())) {
            std::sort(animal.begin(), animal.end(), CompareAnimalbyidasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else {
            std::cerr << "Failed to read an animal file.\n";
        }
    }
}

void DeleteDataAnimal(std::vector<Animal>& animal, unsigned int id,
 std::string file, unsigned short int i) {
    //1 - animal_id 2 - owner_id

    size_t n = 0;
    if (i == 1) {
        while (n < animal.size()) {
            if (animal[n].animal_id == id) {
                animal.erase(animal.begin() + static_cast<__int64>(n));
                break; //there shouldn't be more than 1 entry with the same id
            }
            else {
                n++;
            }

        }
    }
    if (i == 2) {
        while (n < animal.size()) {
            if (animal[n].owner_id == id) {
                animal.erase(animal.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }

        }
    }
    SaveAnimal(animal, file);
}

bool CompareAnimalbyidasc(Animal& a1, Animal& a2) {
    return (a1.animal_id < a2.animal_id);
}

bool CompareAnimalbyiddec(Animal& a1, Animal& a2) {
    return (a1.animal_id > a2.animal_id);
}

bool CompareAnimalbynameasc(Animal& a1, Animal& a2) {
    return (strcmp(a1.name, a2.name) < 0);
}

bool CompareAnimalbynamedec(Animal& a1, Animal& a2) {
    return (strcmp(a1.name, a2.name) > 0);
}

bool CompareAnimalbyspeciesasc(Animal& a1, Animal& a2) {
    return (strcmp(a1.characteristics.species.species,
     a2.characteristics.species.species) < 0);
}

bool CompareAnimalbyspeciesdec(Animal& a1, Animal& a2) {
    return (strcmp(a1.characteristics.species.species,
     a2.characteristics.species.species) > 0);
}

bool CompareAnimalbybreedasc(Animal& a1, Animal& a2) {
    return (strcmp(a1.characteristics.breed, a2.characteristics.breed) < 0);
}

bool CompareAnimalbybreeddec(Animal& a1, Animal& a2) {
    return (strcmp(a1.characteristics.breed, a2.characteristics.breed) > 0);
}

bool CompareAnimalbygenderasc(Animal& a1, Animal& a2) {
    return (strcmp(a1.gender.gender, a2.gender.gender) < 0);
}

bool CompareAnimalbygenderdec(Animal& a1, Animal& a2) {
    return (strcmp(a1.gender.gender, a2.gender.gender) > 0);
}

bool CompareAnimalbyageasc(Animal& a1, Animal& a2) {
    return (a1.age < a2.age);
}

bool CompareAnimalbyagedec(Animal& a1, Animal& a2) {
    return (a1.age > a2.age);
}

bool CompareAnimalbyweightasc(Animal& a1, Animal& a2) {
    return (a1.weight < a2.weight);
}

bool CompareAnimalbyweightdec(Animal& a1, Animal& a2) {
    return (a1.weight > a2.weight);
}

bool CompareAnimalbyoidasc(Animal& a1, Animal& a2) {
    return (a1.owner_id < a2.owner_id);
}

bool CompareAnimalbyoiddec(Animal& a1, Animal& a2) {
    return (a1.owner_id > a2.owner_id);
}

void SortAnimal(std::vector<Animal>& result,
 std::vector<unsigned short int>& prio, std::vector<std::string>& sign) {
    /*prio[]/sign[] 0 - animal id  1 - name  2 - species  3 - breed  4 - gender
    5 - age  6 - weight  7 - ownerid*/
    //1 - most priority  8 - least priority

    if (!(result.empty()) or (result.size() != 1)) {
        for (unsigned short int i = 8; i >= 1; i--) {

            if (i == prio[0]) {
                if (sign[0] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyidasc);
                }
                if (sign[0] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyiddec);
                }
            }

            if (i == prio[1]) {
                if (sign[1] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbynameasc);
                }
                if (sign[1] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbynamedec);
                }
            }

            if (i == prio[2]) {
                if (sign[2] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyspeciesasc);
                }
                if (sign[2] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyspeciesdec);
                }
            }

            if (i == prio[3]) {
                if (sign[3] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbybreedasc);
                }
                if (sign[3] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbybreeddec);
                }
            }

            if (i == prio[4]) {
                if (sign[4] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbygenderasc);
                }
                if (sign[4] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbygenderdec);
                }
            }

            if (i == prio[5]) {
                if (sign[5] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyageasc);
                }
                if (sign[5] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyagedec);
                }
            }

            if (i == prio[6]) {
                if (sign[6] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyweightasc);
                }
                if (sign[6] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyweightdec);
                }
            }

            if (i == prio[7]) {
                if (sign[7] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyoidasc);
                }
                if (sign[7] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareAnimalbyoiddec);
                }
            }
        }
    }
}

std::vector<Animal> FilterAnimal(std::vector<Animal> result,
 std::vector<std::string>& sign, unsigned int& animal_id, std::string& species,
 std::string& breed, std::string& gender,  unsigned int& age,
 float& weight, unsigned int& owner_id) {
    /*sign[] 0 - animal id  1 - species  2 - breed  3 - gender  4 - age
    5 - weight  6 - owner id*/

    size_t n;

    if (sign[0] != "") {
        n = 0;
        if (sign[0] == "=") {
            while (n < result.size()) {
                if (!(result[n].animal_id == animal_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[0] == "!=") {
            while (n < result.size()) {
                if (!(result[n].animal_id != animal_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[1] != "") {
        n = 0;
        if (sign[1] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.species.species,
                 species.c_str()) == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.species.species,
                 species.c_str()) != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[2] != "") {
        n = 0;
        if (sign[2] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.breed, breed.c_str())
                    == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.breed, breed.c_str())
                    != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[3] != "") {
        n = 0;
        if (sign[3] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].gender.gender, gender.c_str()) == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].gender.gender, gender.c_str()) != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[4] != "") {
        n = 0;
        if (sign[4] == "<") {
            while (n < result.size()) {
                if (!(result[n].age < age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "<=") {
            while (n < result.size()) {
                if (!(result[n].age <= age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "=") {
            while (n < result.size()) {
                if (!(result[n].age == age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "!=") {
            while (n < result.size()) {
                if (!(result[n].age != age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == ">=") {
            while (n < result.size()) {
                if (!(result[n].age >= age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == ">") {
            while (n < result.size()) {
                if (!(result[n].age > age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[5] != "") {
        n = 0;
        if (sign[5] == "<") {
            while (n < result.size()) {
                if (!(result[n].weight < weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[5] == "<=") {
            while (n < result.size()) {
                if (!(result[n].weight <= weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[5] == "=") {
            while (n < result.size()) {
                if (!(result[n].weight == weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[5] == "!=") {
            while (n < result.size()) {
                if (!(result[n].weight != weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[5] == ">=") {
            while (n < result.size()) {
                if (!(result[n].weight >= weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[5] == ">") {
            while (n < result.size()) {
                if (!(result[n].weight > weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[6] != "") {
        n = 0;
        if (sign[6] == "=") {
            while (n < result.size()) {
                if (!(result[n].owner_id == owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[6] == "!=") {
            while (n < result.size()) {
                if (!(result[n].owner_id != owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    return result;
}

unsigned int SummaryAnimal(std::vector <Animal> result,
 std::vector<std::string>& sign, std::string& species, std::string& breed,
 std::string& gender, unsigned int& age, float& weight) {
    /*sign[] 0 - species  1 - breed  2 - gender  3 - age  4 - weight*/

    size_t n;

    if (sign[0] != "") {
        n = 0;
        if (sign[0] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.species.species,
                 species.c_str()) == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[0] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.species.species,
                 species.c_str()) != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[1] != "") {
        n = 0;
        if (sign[1] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.breed, breed.c_str())
                    == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].characteristics.breed, breed.c_str())
                    != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[2] != "") {
        n = 0;
        if (sign[2] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].gender.gender, gender.c_str()) == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].gender.gender, gender.c_str()) != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[3] != "") {
        n = 0;
        if (sign[3] == "<") {
            while (n < result.size()) {
                if (!(result[n].age < age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "<=") {
            while (n < result.size()) {
                if (!(result[n].age <= age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "=") {
            while (n < result.size()) {
                if (!(result[n].age == age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "!=") {
            while (n < result.size()) {
                if (!(result[n].age != age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == ">=") {
            while (n < result.size()) {
                if (!(result[n].age >= age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == ">") {
            while (n < result.size()) {
                if (!(result[n].age > age)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[4] != "") {
        n = 0;
        if (sign[4] == "<") {
            while (n < result.size()) {
                if (!(result[n].weight < weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "<=") {
            while (n < result.size()) {
                if (!(result[n].weight <= weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "=") {
            while (n < result.size()) {
                if (!(result[n].weight == weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "!=") {
            while (n < result.size()) {
                if (!(result[n].weight != weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == ">=") {
            while (n < result.size()) {
                if (!(result[n].weight >= weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == ">") {
            while (n < result.size()) {
                if (!(result[n].weight > weight)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    return static_cast<unsigned int>(result.size());
}

std::string StrTabOutputAnimal(Animal& animal, unsigned int& i, int& outputsize,
 char& border, std::vector<bool>& show) {
    /*show[] 0 - animal id  1 - name  2 - breed  3 - species  4 - gender
    5 - age  6 - weight  7 - owner id*/

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (show[0]) {
        str = str + " " + std::to_string(animal.animal_id) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
                border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[1]) {
        str = str + " " + Removespaces(animal.name) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[2]) {
        str = str + " " + Removespaces(animal.characteristics.breed) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[3]) {
        str = str + " " + Removespaces(animal.characteristics.species.species)
            + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[4]) {
        str = str + " " + Removespaces(animal.gender.gender) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }


    if (show[5]) {
        str = str + " " + std::to_string(animal.age) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[6]) {
        str = str + " " + std::to_string(animal.weight) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[7]) {
        str = str + " " + std::to_string(animal.owner_id) + " ";
    }
    if (str[str.size()-1] == border) {
        str[str.size()-1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size()-1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

std::string StrHeaderAnimal(int& outputsize, char& border,
 std::vector<bool>& show) {
    /*show[] 0 - animal id  1 - name  2 - breed  3 - species  4 - gender
    5 - age  6 - weight  7 - owner id */

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;
    if (show[0]) {
        str = str + " Animal ID ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[1]) {
        str = str + " Name ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[2]) {
        str = str + " Breed ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[3]) {
        str = str + " Specie ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[4]) {
        str = str + " Gender ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[5]) {
        str = str + " Years of Age ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[6]) {
        str = str + " Weight ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[7]) {
        str = str + " Owner ID ";
    }
    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

void TableOutputAnimal(std::vector<Animal>& animal, int& outputsize,
 char& border, std::vector<bool>& show) {
    

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderAnimal(outputsize, border, show);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(animal.empty())) {
        for (unsigned int n = 0; n < animal.size(); n++) {
            std::cout << StrTabOutputAnimal(animal[n], n, outputsize, border,
                show);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}


void SaveOwner(std::vector<Owner>& owner, std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(owner.empty())) {
            std::sort(owner.begin(), owner.end(), CompareOwnerbyidasc);
            for (auto& c : owner) {
                Owner* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write an owner file.\n";
    }
}

void ReadOwner(std::vector<Owner>& owner, std::string& file) {

    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Owner>().swap(owner); //makes sure vector is empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Owner)];
            ifs.read(data, sizeof(Owner));
            Owner* pc = reinterpret_cast<Owner*>(data);
            owner.push_back(*pc);
        }
        if (!(owner.empty())) {
            std::sort(owner.begin(), owner.end(), CompareOwnerbyidasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else {
            std::cerr << "Failed to read an owner file.\n";
        }
    }
}

void DeleteDataOwner(std::vector<Owner>& owner,
 std::vector<Appointment>& appointment, std::vector<Animal>& animal,
 unsigned int id, std::string ofile, std::string apfile, std::string afile,
 unsigned short int i) {
    /* i: 1 - none  2 - +delete all animals  3 - +delete all appointments
    4 - +delete all animals and appointments*/

    size_t n = 0;
    if (i == 1) {
        while (n < owner.size()) {
            if (owner[n].owner_id == id) {
                owner.erase(owner.begin() + static_cast<__int64>(n));
                break; //there shouldn't be more than 1 entry with the same id
            }
            else {
                n++;
            }
        }
    }
    if (i == 2) {
        while (n < owner.size()) {
            if (owner[n].owner_id == id) {
                owner.erase(owner.begin() + static_cast<__int64>(n));
                break;
            }
            else {
                n++;
            }
        }
        DeleteDataAnimal(animal, id, afile, 2);
    }
    if (i == 3) {
        while (n < owner.size()) {
            if (owner[n].owner_id == id) {
                owner.erase(owner.begin() + static_cast<__int64>(n));
                break;
            }
            else {
                n++;
            }
        }
        DeleteDataAppointment(appointment, id, apfile, 2);
    }
    if (i == 4) {
        while (n < owner.size()) {
            if (owner[n].owner_id == id) {
                owner.erase(owner.begin() + static_cast<__int64>(n));
                break;
            }
            else {
                n++;
            }
        }
        DeleteDataAnimal(animal, id, afile, 2);
        DeleteDataAppointment(appointment, id, apfile, 2);
    }
    SaveOwner(owner, ofile);
}

void UpdateNoAOwner(std::string& fileowner, std::string& fileanimal) {

    std::vector<Owner> owner{};
    std::vector<Animal> animal{};
    ReadOwner(owner, fileowner);
    ReadAnimal(animal, fileanimal);

    for (auto& o : owner) {
        o.number_of_animals = 0;
        for (auto& a : animal) {
            if (o.owner_id == a.owner_id) {
                o.number_of_animals++;
            }
        }
    }
    SaveOwner(owner, fileowner);
}

bool CompareOwnerbyidasc(Owner& o1, Owner& o2) {
    return (o1.owner_id < o2.owner_id);
}

bool CompareOwnerbyiddec(Owner& o1, Owner& o2) {
    return (o1.owner_id > o2.owner_id);
}

bool CompareOwnerbynameasc(Owner& o1, Owner& o2) {
    return (strcmp(o1.full_name, o2.full_name) < 0);
}

bool CompareOwnerbynamedec(Owner& o1, Owner& o2) {
    return (strcmp(o1.full_name, o2.full_name) > 0);
}

bool CompareOwnerbynoaasc(Owner& o1, Owner& o2) {
    return (o1.number_of_animals < o2.number_of_animals);
}

bool CompareOwnerbynoadec(Owner& o1, Owner& o2) {
    return (o1.number_of_animals > o2.number_of_animals);
}

void SortOwner(std::vector<Owner>& result,
 std::vector<unsigned short int>& prio, std::vector<std::string>& sign) {
    /*prio[]/sign[] 0 - owner id  1 - full name  2 - number of animals*/
    //1 - most priority, 3 - least priority

    if (!(result.empty()) or (result.size() != 1)) {
        for (unsigned short int i = 3; i >= 1; i--) {

            if (i == prio[0]) {
                if (sign[0] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareOwnerbyidasc);
                }
                if (sign[0] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareOwnerbyiddec);
                }
            }

            if (i == prio[1]) {
                if (sign[1] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareOwnerbynameasc);
                }
                if (sign[1] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareOwnerbynamedec);
                }
            }

            if (i == prio[2]) {
                if (sign[2] == "asc") {
                    std::sort(result.begin(), result.end(),
                     CompareOwnerbynoaasc);
                }
                if (sign[2] == "dec") {
                    std::sort(result.begin(), result.end(),
                     CompareOwnerbynoadec);
                }
            }
        }
    }
}

std::vector<Owner> FilterOwner(std::vector<Owner> result,
 std::vector<std::string>& sign, unsigned int& owner_id,
 unsigned int& noa) {
    //sign[] 0 - owner id  1 - number of animals

    size_t n;

    if (sign[0] != "") {
        n = 0;
        if (sign[0] == "=") {
            while (n < result.size()) {
                if (!(result[n].owner_id == owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[0] == "!=") {
            while (n < result.size()) {
                if (!(result[n].owner_id != owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[1] != "") {
        n = 0;
        if (sign[1] == "<") {
            while (n < result.size()) {
                if (!(result[n].number_of_animals < noa)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "<=") {
            while (n < result.size()) {
                if (!(result[n].number_of_animals <= noa)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "=") {
            while (n < result.size()) {
                if (!(result[n].number_of_animals == noa)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "!=") {
            while (n < result.size()) {
                if (!(result[n].number_of_animals != noa)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == ">=") {
            while (n < result.size()) {
                if (!(result[n].number_of_animals >= noa)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == ">") {
            while (n < result.size()) {
                if (!(result[n].number_of_animals > noa)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    return result;
}

unsigned int SummaryOwner(std::vector<Owner> result, unsigned int& noa,
 std::string& noasign) {

    size_t n;

    n = 0;
    if (noasign == "<") {
        while (n < result.size()) {
            if (!(result[n].number_of_animals < noa)) {
                result.erase(result.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }
        }
    }
    if (noasign == "<=") {
        while (n < result.size()) {
            if (!(result[n].number_of_animals <= noa)) {
                result.erase(result.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }
        }
    }
    if (noasign == "=") {
        while (n < result.size()) {
            if (!(result[n].number_of_animals == noa)) {
                result.erase(result.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }
        }
    }
    if (noasign == "!=") {
        while (n < result.size()) {
            if (!(result[n].number_of_animals != noa)) {
                result.erase(result.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }
        }
    }
    if (noasign == ">=") {
        while (n < result.size()) {
            if (!(result[n].number_of_animals >= noa)) {
                result.erase(result.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }
        }
    }
    if (noasign == ">") {
        while (n < result.size()) {
            if (!(result[n].number_of_animals > noa)) {
                result.erase(result.begin() + static_cast<__int64>(n));
            }
            else {
                n++;
            }
        }
    }

    return static_cast<unsigned int>(result.size());
}

std::string StrTabOutputOwner(Owner& owner, unsigned int& i, int& outputsize,
 char& border, std::vector<bool>& show) {
    /*show[] 0 - owner id  1 - full name  2 - number of animals*/

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (show[0]) {
        str = str + " " + std::to_string(owner.owner_id) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[1]) {
        str = str + " " + Removespaces(owner.full_name) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[2]) {
        str = str + " " + std::to_string(owner.number_of_animals) + " ";
    }
    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 2; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

std::string StrHeaderOwner(int& outputsize, char& border,
 std::vector<bool>& show) {
    /*show[] 0 - owner id  1 - full name  2 - number of animals*/

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;
    if (show[0]) {
        str = str + " Owner ID ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[1]) {
        str = str + " Full Name ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[2]) {
        str = str + " Number of Animals ";
    }
    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

void TableOutputOwner(std::vector<Owner>& owner, int& outputsize, char& border,
 std::vector<bool>& show) {

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderOwner(outputsize, border, show);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(owner.empty())) {
        for (unsigned int n = 0; n < owner.size(); n++) {
            std::cout << StrTabOutputOwner(owner[n], n, outputsize, border,
             show);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}


void SaveAppointment(std::vector<Appointment>& appointment,
 std::string& file) {

    if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {
        if (!(appointment.empty())) {
            std::sort(appointment.begin(), appointment.end(),
             CompareAppointmentbyidasc);
            for (auto& c : appointment) {
                Appointment* pc = &c;
                char* data = reinterpret_cast<char*>(pc);
                ofs.write(data, sizeof(c));
            }
        }
    }
    else {
        std::cerr << "Failed to write an appointment file.\n";
    }
}

void ReadAppointment(std::vector<Appointment>& appointment,
 std::string& file) {
    
    if (std::ifstream ifs{ file, std::ios::binary | std::ios::ate }) {
        std::vector<Appointment>().swap(appointment); //makes sure vector is
        //empty
        const auto fsize = ifs.tellg();
        ifs.seekg(0);
        while (ifs.tellg() < fsize) {
            char data[sizeof(Appointment)];
            ifs.read(data, sizeof(Appointment));
            Appointment* pc = reinterpret_cast<Appointment*>(data);
            appointment.push_back(*pc);
        }
        if (!(appointment.empty())) {
            std::sort(appointment.begin(), appointment.end(),
             CompareAppointmentbyidasc);
        }
    }
    else {
        if (std::ofstream ofs{ file, std::ios::binary | std::ios::trunc }) {}
        else{
            std::cerr << "Failed to read an appointment file.\n";
        }
    }
}

void DeleteDataAppointment(std::vector<Appointment>& appointment,
 unsigned int id, std::string file, unsigned short int i) {
    /*1 - appointment_id 2 - owner_id 3 - animal_id*/

    size_t n = 0;
    if (i == 1) {
        while (n < appointment.size()) {
            if (appointment[n].appointment_id == id) {
                appointment.erase(appointment.begin() +
                 static_cast<__int64>(n));
                break; //there shouldn't be more than 1 entry with the same id
            }
            else {
                n++;
            }

        }
    }
    if (i == 2) {
        while (n < appointment.size()) {
            if (appointment[n].owner_id == id) {
                appointment.erase(appointment.begin() +
                 static_cast<__int64>(n));
            }
            else {
                n++;
            }

        }
    }
    if (i == 3) {
        while (n < appointment.size()) {
            if (appointment[n].animal_id == id) {
                appointment.erase(appointment.begin() +
                 static_cast<__int64>(n));
            }
            else {
                n++;
            }

        }
    }
    SaveAppointment(appointment, file);
}

bool CompareAppointmentbyidasc(Appointment& ap1, Appointment& ap2) {
    return (ap1.appointment_id < ap2.appointment_id);
}

bool CompareAppointmentbyiddec(Appointment& ap1, Appointment& ap2) {
    return (ap1.appointment_id > ap2.appointment_id);
}

bool CompareAppointmentbyoidasc(Appointment& ap1, Appointment& ap2) {
    return (ap1.owner_id < ap2.owner_id);
}

bool CompareAppointmentbyoiddec(Appointment& ap1, Appointment& ap2) {
    return (ap1.owner_id > ap2.owner_id);
}

bool CompareAppointmentbyaidasc(Appointment& ap1, Appointment& ap2) {
    return (ap1.animal_id < ap2.animal_id);
}

bool CompareAppointmentbyaiddec(Appointment& ap1, Appointment& ap2) {
    return (ap1.animal_id > ap2.animal_id);
}

bool CompareAppointmentbydateasc(Appointment& ap1, Appointment& ap2) {
    return (ap1.date < ap2.date);
}

bool CompareAppointmentbydatedec(Appointment& ap1, Appointment& ap2) {
    return (ap1.date > ap2.date);
}

bool CompareAppointmentbyreasonasc(Appointment& ap1, Appointment& ap2) {
    return (strcmp(ap1.reason.reason, ap2.reason.reason) < 0);
}

bool CompareAppointmentbyreasondec(Appointment& ap1, Appointment& ap2) {
    return (strcmp(ap1.reason.reason, ap2.reason.reason) > 0);
}

void SortAppointment(std::vector<Appointment>& result,
 std::vector<unsigned short int>& prio, std::vector<std::string>& sign) {
    /*prio[]/sign[] 0 - appointment id  1 - owner id  2 - animal id  3 - date
    4 - reason*/
    //1 - most priority, 5 - least priority

    if (!(result.empty()) or (result.size() != 1)) {
        for (unsigned short int i = 5; i >= 1; i--) {

            if (i == prio[0]) {
                if (sign[0] == "asc") {
                    std::sort(result.begin(), result.end(), CompareAppointmentbyidasc);
                }
                if (sign[0] == "dec") {
                    std::sort(result.begin(), result.end(), CompareAppointmentbyiddec);
                }
            }

            if (i == prio[1]) {
                if (sign[1] == "asc") {
                    std::sort(result.begin(), result.end(), CompareAppointmentbyoidasc);
                }
                if (sign[1] == "dec") {
                    std::sort(result.begin(), result.end(), CompareAppointmentbyoiddec);
                }
            }

            if (i == prio[2]) {
                if (sign[2] == "asc") {
                    std::sort(result.begin(), result.end(), CompareAppointmentbyaidasc);
                }
                if (sign[2] == "dec") {
                    std::sort(result.begin(), result.end(), CompareAppointmentbyaiddec);
                }
            }

            if (i == prio[3]) {
                if (sign[3] == "asc") {
                    std::sort(result.begin(), result.end(),
                        CompareAppointmentbydateasc);
                }
                if (sign[3] == "dec") {
                    std::sort(result.begin(), result.end(),
                        CompareAppointmentbydatedec);
                }
            }

            if (i == prio[4]) {
                if (sign[4] == "asc") {
                    std::sort(result.begin(), result.end(),
                        CompareAppointmentbyreasonasc);
                }
                if (sign[4] == "dec") {
                    std::sort(result.begin(), result.end(),
                        CompareAppointmentbyreasondec);
                }
            }
        }
    }
}

std::vector<Appointment> FilterAppointment(std::vector<Appointment> result,
 std::vector<std::string>& sign, unsigned int& appointment_id,
 unsigned int& owner_id, unsigned int& animal_id, time_t& date,
 std::string& reason) {
    /*sign[] 0 - appointment id  1 - owner id  2 - animal id  3 - date
    4 - reason*/

    size_t n;

    if (sign[0] != "") {
        n = 0;
        if (sign[0] == "=") {
            while (n < result.size()) {
                if (!(result[n].appointment_id == appointment_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[0] == "!=") {
            while (n < result.size()) {
                if (!(result[n].appointment_id != appointment_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[1] != "") {
        n = 0;
        if (sign[1] == "=") {
            while (n < result.size()) {
                if (!(result[n].owner_id == owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "!=") {
            while (n < result.size()) {
                if (!(result[n].owner_id != owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[2] != "") {
        n = 0;
        if (sign[2] == "=") {
            while (n < result.size()) {
                if (!(result[n].animal_id == animal_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == "!=") {
            while (n < result.size()) {
                if (!(result[n].animal_id != animal_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[3] != "") {
        n = 0;
        if (sign[3] == "<") {
            while (n < result.size()) {
                if (!(result[n].date < date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "<=") {
            while (n < result.size()) {
                if (!(result[n].date <= date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "=") {
            while (n < result.size()) {
                if (!(result[n].date == date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "!=") {
            while (n < result.size()) {
                if (!(result[n].date != date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == ">=") {
            while (n < result.size()) {
                if (!(result[n].date >= date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == ">") {
            while (n < result.size()) {
                if (!(result[n].date > date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[4] != "") {
        n = 0;
        if (sign[4] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].reason.reason, reason.c_str()) == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[4] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].reason.reason, reason.c_str()) != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    return result;
}

unsigned int SummaryAppointment(std::vector<Appointment> result,
 std::vector<std::string>& sign, unsigned int& owner_id,
 unsigned int& animal_id, time_t& date, std::string& reason) {
    /*sign[] 0 - owner id  1 - animal id  2 - date  3 - reason*/

    size_t n;

    if (sign[0] != "") {
        n = 0;
        if (sign[0] == "=") {
            while (n < result.size()) {
                if (!(result[n].owner_id == owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[0] == "!=") {
            while (n < result.size()) {
                if (!(result[n].owner_id != owner_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[1] != "") {
        n = 0;
        if (sign[1] == "=") {
            while (n < result.size()) {
                if (!(result[n].animal_id == animal_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[1] == "!=") {
            while (n < result.size()) {
                if (!(result[n].animal_id != animal_id)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[2] != "") {
        n = 0;
        if (sign[2] == "<") {
            while (n < result.size()) {
                if (!(result[n].date < date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == "<=") {
            while (n < result.size()) {
                if (!(result[n].date <= date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == "=") {
            while (n < result.size()) {
                if (!(result[n].date == date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == "!=") {
            while (n < result.size()) {
                if (!(result[n].date != date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == ">=") {
            while (n < result.size()) {
                if (!(result[n].date >= date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[2] == ">") {
            while (n < result.size()) {
                if (!(result[n].date > date)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    if (sign[3] != "") {
        n = 0;
        if (sign[3] == "=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].reason.reason, reason.c_str()) == 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
        if (sign[3] == "!=") {
            while (n < result.size()) {
                if (!(strcmp(result[n].reason.reason, reason.c_str()) != 0)) {
                    result.erase(result.begin() + static_cast<__int64>(n));
                }
                else {
                    n++;
                }
            }
        }
    }

    return static_cast<unsigned int>(result.size());
}

std::string StrTabOutputAppointment(Appointment& appointment, unsigned int& i,
 int& outputsize, char& border, std::vector<bool>& show) {
    /*show[] 0 - appointment id  1 - owner id  2 - animal id  3 - date
    4 - reason  5 - commentary*/

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " *" + std::to_string(i) + " ";
    if (str.size() >= n * (outputsize + 1)) {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border);
        n = (str.size() / outputsize) + 1;
    }
    else {
        str = str + border;
    }

    if (show[0]) {
        str = str + " " + std::to_string(appointment.appointment_id) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[1]) {
        str = str + " " + std::to_string(appointment.owner_id) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[2]) {
        str = str + " " + std::to_string(appointment.animal_id) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[3]) {
        struct tm ptm;
        time_t temptime = appointment.date;
        localtime_s(&ptm, &temptime);
        str = str + " " + std::to_string(ptm.tm_mday) + "." +
         std::to_string(ptm.tm_mon) + "." + std::to_string(ptm.tm_year + 1900)
         + " " + std::to_string(ptm.tm_hour) + ":" + std::to_string(ptm.tm_min)
         + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[4]) {
        str = str + " " + Removespaces(appointment.reason.reason) + " ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[5]) {
        str = str + " " + Removespaces(appointment.commentary) + " ";
    }
    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 2; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

std::string StrHeaderAppointment(int& outputsize, char& border,
 std::vector<bool>& show) {
    /*show[] 0 - appointment id  1 - owner id  2 - animal id  3 - date
    4 - reason  5 - commentary*/

    size_t n = 1;

    std::string str;
    str.push_back(border);
    str = str + " No " + border;
    if (show[0]) {
        str = str + " Appointment ID ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[1]) {
        str = str + " Owner ID ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[2]) {
        str = str + " Animal ID ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[3]) {
        str = str + " Date ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[4]) {
        str = str + " Reason ";
        if (str.size() > n * (outputsize + 1)) {
            Outputconverter(str, outputsize, static_cast<unsigned int>(n),
             true, border);
            n = (str.size() / outputsize) + 1;
        }
        else {
            str = str + border;
        }
    }

    if (show[5]) {
        str = str + " Commentary ";
    }
    if (str[str.size() - 1] == border) {
        str[str.size() - 1] = ' ';
        for (auto c = str.size(); c < n * (outputsize + 1) - 1; c++) {
            str.push_back(' ');
        }
        str[str.size() - 1] = border;
        str.push_back('\n');
    }
    else {
        Outputconverter(str, outputsize, static_cast<unsigned int>(n), true,
         border, true);
    }

    return str;
}

void TableOutputAppointment(std::vector<Appointment>& appointment,
 int& outputsize, char& border, std::vector<bool>& show) {

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
    std::cout << StrHeaderAppointment(outputsize, border, show);
    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';

    if (!(appointment.empty())) {
        for (unsigned int n = 0; n < appointment.size(); n++) {
            std::cout << StrTabOutputAppointment(appointment[n], n, outputsize,
                border, show);
        }
    }
    else {
        std::cout << border;
        for (int n = 2; n <= outputsize - 1; n++) {
            std::cout << ' ';
        }
        std::cout << border << '\n';
    }

    for (int n = 1; n <= outputsize; n++) {
        std::cout << border;
    }
    std::cout << '\n';
}