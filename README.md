# Проект Библиотека

## Описание
Това е малка C++ система за управление на библиотека с книги, членове и заеми.  
Демонстрира основни ООП концепции:

- конструктори и деструктори
- капсулация (private членове, getters и setters)
- const-коректност
- статични членове и методи
- валидация на данни
- добри ООП практики в реалистичен контекст.

## Структура на проекта
```
library/
├── Book.h
├── Author.h
├── Member.h
├── Loan.h
├── Library.h
├── main.cpp
└── README.md
```

## Класове

### Book
Представя книга с основни характеристики.

- **Членове:** title, author, year, price, isbn  
- **Статични членове:** totalBooks  
- **Методи:** конструктори, getters/setters, `to_string()`, `getTotalBooks()`

### Author
Представя автор.

- **Членове:** name, birthYear  
- **Методи:** конструктори, getters/setters, `to_string()`

### Member
Представя член на библиотеката.

- **Членове:** name, memberId, yearJoined  
- **Методи:** конструктори, getters/setters, `isValid()`, `to_string()`

### Loan
Представя заем на книга.

- **Членове:** isbn, memberId, startDate, dueDate, returned  
- **Методи:** конструктор с валидация, getters, `markReturned()`, `isOverdue()`, `to_string()`

### Library
Представя библиотека с книги, членове и заеми.

- **Членове:** vectors от Book, Member, Loan  
- **Методи:** добавяне на книги/членове, проверка за наличност, заеми и връщане на книги, търсене по автор, `to_string()`

## Компилация и изпълнение
Отворете терминал в директорията на проекта и изпълнете:

```bash
g++ -std=c++17 -Wall -Wextra -o library.cpp  main.cpp
```

Стартирайте програмата:

```bash
library.cpp
```

## Примерен изход
![alt text](<Screenshot 2025-12-06 000753.png>)
