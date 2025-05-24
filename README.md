# ZoricBankApp

A modern C++ banking application built using **Qt6** for the GUI and **PostgreSQL** for secure backend data management.

---

##  Features

-  **Qt6 GUI**
  - Clean login and register screens
  - Styled inputs and buttons with Qt Style Sheets
  - Register popup window
-  **PostgreSQL Integration**
  - Database connection using `libpqxx`
  - `.env` config loader to hide credentials
  - Auto table creation on first launch
-  **Modular Structure**
  - Separation of frontend (UI) and backend (DB logic)
  - Header/source file organization
-  **Dynamic SQL Loading**
  - Executes SQL schema from `Tables.sql` at startup

---

##  Built With

- [C++17](https://en.cppreference.com/)
- [Qt6](https://www.qt.io/)
- [PostgreSQL](https://www.postgresql.org/)
- [libpqxx](https://github.com/jtv/libpqxx)
- CMake

---

##  Project Structure

```
qtlearn/
├── main.cpp
├── FrontEnd/
│   ├── MainWindow/ (Login + Register UI)
│   └── RegisterLogin/
├── BackEnd/
│   ├── DataServerEndPoint/ (DB config + connector)
│   └── Tables/ (SQL loader)
├── Tables.sql
└── CMakeLists.txt
```

---

## 🛠️ Getting Started

### 1. Install dependencies (macOS example)

```bash
brew install qt libpq libpqxx
```

### 2. Link PostgreSQL libraries

```bash
brew link --overwrite --force libpq
```

### 3. Build the project

```bash
cmake -B build -S .
cmake --build build
./build/qtlearn
```

### 4. Set up `.env`

```
DB_NAME=bankdb
DB_USER=youruser
DB_PASSWORD=yourpass
DB_HOST=localhost
DB_PORT=5432
```

---

##  Future Features

- Admin dashboard
- Transaction history
- Transfer between users
- Dark/light mode switch
- Unit tests and CI pipeline

---

## License

