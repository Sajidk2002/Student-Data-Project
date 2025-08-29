# Student Record Management System (C)

A console-based Student Record Management System implemented using a singly linked list.

## Features
- Add, delete, modify, display student records
- Sort by name, marks, or roll number (ascending/descending via reverse)
- Save to file (`student.txt`) and load from file
- Reverse the list, delete all, save-and-exit option

## Build & Run

### Option 1: Using Make (recommended)
```bash
make
./student
```

### Option 2: Using gcc directly
```bash
gcc src/student.c -o student
./student
```

> The program reads/writes data to `student.txt` in the current directory.

## Menu (runtime)
```
a/A) add_node    b/B) delete_node   c/C) print_node
d/D) modify_node e/E) save_file     f/F) read_file
g/G) sort_data   i/I) delete_all    R/r) reverse
s) save and exit E) exit (no save)
```

## Project Structure
```
.
├── src/
│   ├── header.h
│   └── student.c
├── .gitignore
├── LICENSE
├── Makefile
└── README.md
```

## Author
**Muhammad Sajid K**  
- Email: muhammadsajidk183@gmail.com  
- LinkedIn: https://linkedin.com/in/muhammad-sajid-k-620b68257
```

This repository was scaffolded for quick GitHub publishing. Replace `YOUR_USERNAME` in the push commands with your GitHub handle.
