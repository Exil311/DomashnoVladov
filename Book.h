#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include "Author.h"
using namespace std;

class Book {
private:
    string title;
    Author author;
    int year;
    double price;
    string isbn;

    static int totalBooks;

public:
    Book() 
        : title("Unknown"), author(), year(2000), price(0.0), isbn("N/A") 
    { totalBooks++; }

    Book(const string& t, const Author& a, int y, double p, const string& i)
        : title(t), author(a), year(2000), price(0.0), isbn(i) 
    {
        setYear(y);
        setPrice(p);
        totalBooks++;
    }

    Book(const Book& other)
        : title(other.title), author(other.author), year(other.year), 
          price(other.price), isbn(other.isbn) 
    { totalBooks++; }

    Book(Book&& other) noexcept
        : title(move(other.title)), author(move(other.author)), year(other.year),
          price(other.price), isbn(move(other.isbn)) 
    { totalBooks++; }

    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }

    Book& operator=(Book&& other) noexcept {
        if (this != &other) {
            title = move(other.title);
            author = move(other.author);
            year = other.year;
            price = other.price;
            isbn = move(other.isbn);
        }
        return *this;
    }
    ~Book() { totalBooks--; }

    string getTitle() const { 
        return title; 
    }
    Author getAuthor() const { 
        return author; 
    }
    int getYear() const { 
        return year; 
    }
    double getPrice() const { 
        return price; 
    }
    string getISBN() const { 
        return isbn; 
    }

    void setYear(int y) { 
        if (y >= 1450 && y <= 2025) year = y; 
    }
    void setPrice(double p) { 
        if (p >= 0) price = p; 
    }

    string to_string() const {
        ostringstream oss;
        oss << left << setw(16) << title
            << left << setw(18) << author.getName() 
            << "(" << author.getBirthYear() << ")"
            << right << setw(6) << year
            << setw(9) << fixed << setprecision(2) << price
            << setw(12) << isbn;
        return oss.str();
    }

};
int Book::totalBooks = 0;
