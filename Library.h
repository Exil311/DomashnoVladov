#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addMember(const Member& m) {
        if (m.isValid())
            members.push_back(m);
    }

    bool hasBook(const string& isbn) const {
        return any_of(books.begin(), books.end(), [&](const Book& b){ return b.getISBN() == isbn; });
    }

    bool isBookAvailable(const string& isbn) const {
        for (const Loan& l : loans)
            if (l.getISBN() == isbn && !l.isReturned())
                return false;
        return hasBook(isbn);
    }

    bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due) {
        if (!hasBook(isbn) || !isBookAvailable(isbn))
            return false;
        bool memberExists = any_of(members.begin(), members.end(),
                                   [&](const Member& m){ return m.getId() == memberId; });
        if (!memberExists) return false;
        loans.emplace_back(isbn, memberId, start, due);
        return true;
    }

    bool returnBook(const string& isbn, const string& memberId) {
        for (Loan& l : loans)
            if (l.getISBN() == isbn && l.getMemberId() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        return false;
    }

    vector<Book> findByAuthor(const string& authorName) const {
        vector<Book> result;
        for (const Book& b : books)
            if (b.getAuthor().getName().find(authorName) != string::npos)
                result.push_back(b);
        return result;
    }

    vector<Book> getBooks() const { 
        return books; 
    }
    vector<Member> getMembers() const { 
        return members; 
    }
    vector<Loan> getLoans() const { 
        return loans; 
    }

    string to_string() const {
        int activeLoans = 0;
        for (const Loan& l : loans) {
            if (!l.isReturned()) activeLoans++;
        }
        ostringstream oss;
        oss << "Library Snapshot >> Books: " << books.size()
            << ", Members: " << members.size()
            << ", Current Loans: " << activeLoans;
        return oss.str();
    }
};
