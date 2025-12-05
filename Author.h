#pragma once
#include <string>
using namespace std;

class Author {
private:
    string name;
    int birthYear;

public:
    Author() : name("Unknown"), birthYear(2000) {
    }
    Author(const string& n, int by) : name(n), birthYear(2000) {setBirthYear(by);}

    string getName() const { 
        return name;
    }
    int getBirthYear() const { 
        return birthYear; 
    }

    void setBirthYear(int by) {
        if (by >= 1850 && by <= 2025)
            birthYear = by;
    }

    string to_string() const {
        return name + " (" + std::to_string(birthYear) + ")";
    }
};
