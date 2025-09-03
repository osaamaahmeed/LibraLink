# 📚 LibraLink

LibraLink is a simple C++ library management system that demonstrates basic linked list operations for managing books in a library. The project provides functionality to add, remove, search, sort, and display books using a doubly linked list structure.

## ✨ Features

- ➕ Add books to the head, tail, or a specific position in the library.
- 🗑️ Remove books from the head, tail, by index, or by matching book details.
- 🔎 Search for books by title, author, or publication year.
- 🔃 Sort books by title, author, or publication year (ascending and descending).
- 📖 Display all books or display in reverse order.
- 🧹 Clear the library.
- 🔢 Count the number of books.

## 🚀 Usage

The main functionality is demonstrated in `main.cpp`. Compile and run the program to see how books are managed in the library.

### Example

```bash
g++ main.cpp -o libra
./libra
```

## 🏗️ Structure

- `Book` class: Represents a book with title, author, publication year, and links to the next/previous books.
- `Library` class: Manages the collection of books and provides all operations.

## ⚙️ Requirements

- C++ compiler (e.g., g++)

## 📜 License

This project is for educational purposes.
