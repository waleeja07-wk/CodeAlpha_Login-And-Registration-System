# Login and Registration System (C++)

A simple console-based Login and Registration System built in C++ as part of the CodeAlpha C++ Internship (Task 2).

## Features

- **Register** a new user with a username and password
- **Duplicate username validation** — prevents two users from registering the same username
- **Data storage** — credentials are saved to a file (`User.txt`) so accounts survive after the program closes
- **Login** function that verifies a username and password against stored credentials
- **Success/error messages** for every action (registration, login, invalid input, etc.)
- Handles invalid menu input (e.g. typing letters instead of numbers) without crashing or hanging

## How It Works

- User credentials are stored as `username password` pairs, one per line, in `User.txt`
- On startup, the program loads any existing users from `User.txt` into memory using two parallel vectors (`usernames` and `passwords`)
- New registrations are appended to the file (existing users are never overwritten)
- Login checks the entered username and password against the stored records

## Usage

When you run the program, you'll see a menu:

```
====LOGIN AND REGISTRATION SYSTEM====
1. REGISTER USER
2. LOGIN TO AN EXISTING ACCOUNT
3. EXIT
ENTER CHOICE:
```

- Choose **1** to register a new account
- Choose **2** to log in with an existing account
- Choose **3** to exit the program

## File Structure

```
.
├──.gitignore                             # Remove .exe files
├── Login-And-Registration-System.cpp     # Source code
├── User.txt                              # Auto-generated file storing registered users (created on first run)
└── README.md                             # System Description
```

## Notes / Limitations

- Passwords are currently stored as **plain text** in `User.txt`, which is fine for a learning project but not suitable for production use. A real-world system should hash passwords (e.g. with bcrypt or Argon2) before storing them.
- Usernames and passwords cannot contain spaces, since input is read word-by-word with `cin >>`.

## Author

Built as part of the CodeAlpha C++ Programming Internship.
