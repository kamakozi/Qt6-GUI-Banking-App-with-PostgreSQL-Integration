# ZoricBankApp

A modern C++ banking application built using **Qt6** for the GUI and **PostgreSQL** for secure backend data management.

---

##  Features

###  UI (Frontend)
- Clean and responsive **Qt6 interface**
- Modern dark-themed windows:
  - Login & Registration
  - Deposit & Withdrawal
  - Account Info with role display
- Styled inputs and buttons (Qt Style Sheets)
- Error handling with helpful messages (invalid email, wrong credentials, etc.)

### Database (Backend)
- PostgreSQL integration via **libpqxx**
- Automatic table creation using SQL schema (`Tables.sql`)
- Secure `.env` loading for connection credentials
- Deposit/withdrawal operations directly update database

### Code Architecture
- Modular file structure: clean separation of UI and logic
- Header/source file separation for maintainability
- Dynamic SQL schema loading on startup

---

## Built With

- [C++17](https://en.cppreference.com/)
- [Qt6](https://www.qt.io/)
- [PostgreSQL](https://www.postgresql.org/)
- [libpqxx](https://github.com/jtv/libpqxx)
- CMake

---


##  Getting Started

### 1. Install Dependencies (macOS example)

brew install qt libpq libpqxx

### 2. Link PostgreSQL libraries (if needed)

brew link --overwrite --force libpq

### 3. Build & Run

cmake -B build -S .
cmake --build build
./build/qtlearn

### 4. Set up `.env`

Create a file named `.env` in your project root:

DB_NAME=bankdb
DB_USER=youruser
DB_PASSWORD=yourpass
DB_HOST=localhost
DB_PORT=5432

---

##  Future Features

- Admin dashboard (manage users, roles)
- User transaction history
- In-app user-to-user transfers
- Toggle dark/light themes
- Unit tests and CI integration

---


