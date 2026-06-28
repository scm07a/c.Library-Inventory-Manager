# Library Inventory Manager (C)

A console-based Library Inventory Manager written in C, built to practice modular programming, file handling, and software design principles.

## Features

* Add new books
* View all books
* Search books by ID
* Edit book details (title, author, price)
* Borrow and return books
* Soft delete books
* Restore deleted books
* View deleted books
* Persistent binary file storage
* Reset saved library data

---

## Technologies

* C11
* CMake
* Binary File I/O (`fread` / `fwrite`)
* Modular Programming
* Git & GitHub

---

## Project Structure

```text
LibraryV2/
├── CMakeLists.txt
├── README.md
├── src/
│   ├── main.c
│   ├── library.c
│   └── ValidIO.c
├── include/
│   ├── library.h
│   └── ValidIO.h
├── data/
│   └── libr.dat
└── build/
```

---

## Building the Project

Configure the project:

```bash
cmake -B build -G Ninja
```

Build the executable:

```bash
cmake --build build
```

Run the executable:

```bash
./build/LibraryV2
```

On Windows PowerShell:

```powershell
.\build\LibraryV2.exe
```

---

## How It Works

Books are stored in a fixed-size array of `Book` structures.

Each book stores:

* ID
* Title
* Author
* Price
* Availability status
* Deletion status

Instead of permanently removing books, the project uses **soft deletion**, allowing deleted books to be restored later.

Library data is saved to a binary file using `fwrite()` and loaded using `fread()` whenever the application starts.

---

## Design Decisions

* Modular project structure (`src/` and `include/`)
* Separation of concerns:

  * User interface (`main.c`)
  * Library logic (`library.c`)
  * Input validation (`ValidIO.c`)
* Binary persistence
* Soft delete instead of physical deletion
* Fixed-size array for simplicity

---

## What I Learned

Through this project I practiced:

* Modular C programming
* Designing multi-file projects
* Binary file handling
* Struct-based data management
* Input validation
* CRUD application design
* Project organization
* Building projects with CMake
* Version control using Git and GitHub

---

## Current Limitations

* Fixed maximum number of books
* Linear search
* No dynamic memory allocation
* No database backend
* Single-user application

---

## Future Improvements

* Dynamic memory allocation
* Improved searching and sorting
* SQLite integration
* User authentication
* GUI version using C++
* Additional reporting and statistics

---

## Author

Mohamed

A personal learning project created to strengthen C programming fundamentals while applying real-world software engineering practices.
