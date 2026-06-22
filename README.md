# Library Inventory Manager (C)

A console-based library management system written in C.  
Built to practice data structures, file handling, and modular programming.

---

## Features

- Add books
- View all books
- Search books by ID
- Delete books (soft delete)
- Restore deleted books
- View deleted books
- Edit book details (title, author, price)
- Borrow / return system (availability tracking)
- Save and load data using binary files

---

## Data Persistence

- Uses `fwrite` / `fread` to store data in `libr.dat`
- Automatically loads data on startup
- Supports resetting saved data

---

## Project Structure

- `main.c` → menu system and program flow
- `library.c` → core book operations
- `library.h` → function declarations + Book struct
- `ValidIO.c` → input validation functions
- `ValidIO.h` → input validation declarations

---

## How to Compile

```bash
gcc main.c library.c ValidIO.c -o library
./library

---

## How It Works

- Books are stored in a static array in memory.
- Each book is represented using a `struct` containing:
  - ID
  - Title
  - Author
  - Price
  - Availability status
  - Deletion flag

- Instead of removing books from memory, deletion is handled logically using a flag (`isDeleted`).
- This allows recovery (restore feature) without losing data.

- All data is persisted using binary file storage:
  - First stores `bookCount`
  - Then stores the full array of `Book` structs

---

## File Handling Logic

- On **Save**:
  - `bookCount` is written first
  - then the `books[]` array is written using `fwrite`

- On **Load**:
  - `bookCount` is read first
  - then that many `Book` structs are loaded into memory

- On **Reset**:
  - `bookCount` is set to 0
  - file is overwritten with empty state

---

## Key Design Decisions

- Fixed-size array for simplicity and learning purposes
- Linear search for simplicity (with ID filtering)
- Soft delete instead of hard delete
- Separation of concerns:
  - UI (main)
  - Logic (library.c)
  - Input validation (ValidIO.c)

---

## What I Learned

- How to structure a multi-file C project
- How binary file I/O actually works in practice
- How to design simple CRUD systems
- How to manage state using structs + flags
- Why separating validation logic improves code clarity

---

## Known Limitations

- Fixed maximum capacity (`MAX_BOOKS`)
- No dynamic memory resizing
- No indexing optimization (linear search only)
- No database integration
- No concurrency or multi-user support

---

## Future Improvements

- Replace array with dynamic structure (linked list / dynamic vector)
- Improve search (hashing or indexing)
- Add sorting by title/author
- Add GUI version (C++ Qt / GTK)
- Replace file system with SQLite database
- Add user roles (admin / user system)

---

## Author

Mohamed — C programming learning project focused on building real-world system design skills.