#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Loan {
private:
    string isbn;
    string memberId;
    string startDate;
    string dueDate;
    bool returned;

public:
    Loan(const string& i, const string& mId, const string& start, const string& due)
        : isbn(i), memberId(mId), startDate(start), dueDate(due), returned(false) {
        if (dueDate < startDate) dueDate = startDate;
    }

    string getISBN() const {
        return isbn; 
    }
    string getMemberId() const { 
        return memberId; 
    }
    string getStartDate() const { 
        return startDate; 
    }
    string getDueDate() const { 
        return dueDate; 
    }
    bool isReturned() const { 
        return returned; 
    }
    void markReturned() { 
        returned = true; 
    }

    bool isOverdue(const string& today) const {
        return (!returned && dueDate < today);
    }

    string to_string() const {
        ostringstream oss;
        oss << "[Loan] Book: " << isbn
            << " | MemberID: " << memberId
            << " | From: " << startDate
            << " to " << dueDate
            << " | Status: " << (returned ? "Returned" : "Active");
        return oss.str();
}
};

