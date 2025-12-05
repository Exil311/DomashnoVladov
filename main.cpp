#include <iostream>
#include <iomanip>
#include "Library.h"
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "Author.h"

using namespace std;

int main() {
    Library lib;

    Author vazov("Ivan Vazov", 1850);
    lib.addBook(Book("Pod igoto", vazov, 1894, 25.50, "ISBN-001"));
    lib.addBook(Book("Nema zemya", vazov, 1900, 18.90, "ISBN-002"));
    lib.addMember(Member("Petar Petrov", "M001", 2023));

    cout << "\n===== Na Misho bibliotekata =====\n";
    cout << lib.to_string() << "\n";

    cout << "Members:\n";
    for (const auto& m : lib.getMembers())
        cout << left << setw(18) << m.getName()
             << setw(8) << m.getId()
             << "Joined: " << m.getYearJoined() << "\n";
    cout << "\n";

    cout << "Books:\n";
    cout << left << setw(18) << "Title"
         << left << setw(22) << "Author"
         << right << setw(6) << "Year"
         << setw(9) << "Price"
         << setw(12) << "ISBN" << "\n";
    for (const auto& b : lib.getBooks())
        cout << b.to_string() << "\n";

    cout << "\nCreating loan for ISBN-001...\n";
    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        cout << "Loan created.\n";
    else
        cout << "Loan failed.\n";

    cout << "\nActive loans:\n";
    for (const auto& l : lib.getLoans())
        if (!l.isReturned())
            cout << l.to_string() << "\n";

    cout << "\nAvailability check for ISBN-001:\n";
    cout << (lib.isBookAvailable("ISBN-001") ? "Available\n" : "Not available\n");

    cout << "\nReturning ISBN-001...\n";
    if(lib.returnBook("ISBN-001", "M001"))
        cout << "Returned successfully\n";
    else
        cout << "Return failed\n";

    cout << "\nBooks by author containing 'Vazov':\n";
    for (const auto& bk : lib.findByAuthor("Vazov"))
        cout << bk.to_string() << "\n";

    cout << "\n===== Made by Misho(22418) =====\n";

    return 0;
}
