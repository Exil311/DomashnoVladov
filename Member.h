#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Member {
private:
    string name;
    string memberId;
    int yearJoined;

public:

    Member() : name("Unknown"), memberId("N/A"), yearJoined(2025) {}

    Member(const string& n, const string& id, int y)
        : name(n), memberId(id), yearJoined(y) {}

    string getName() const {   
        return name; 
    }
    string getId() const { 
        return memberId; 
    }
    int getYearJoined() const { 
        return yearJoined; 
    }

    bool isValid() const { 
        return !memberId.empty(); 
    }

    string to_string() const {
        ostringstream oss;
        oss << left << setw(18) << name
            << left << setw(8) << memberId
            << "Joined: " << yearJoined;
        return oss.str();
    }
};

