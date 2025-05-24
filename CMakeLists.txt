cmake_minimum_required(VERSION 3.31)
project(qtlearn)

set(CMAKE_CXX_STANDARD 17)

# Qt setup
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ✅ Find OpenSSL
set(OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@3")
set(OPENSSL_INCLUDE_DIR "/opt/homebrew/opt/openssl@3/include")
set(OPENSSL_LIBRARIES "/opt/homebrew/opt/openssl@3/lib")
find_package(OpenSSL REQUIRED)

# PostgreSQL / libpqxx paths
include_directories("/opt/homebrew/Cellar/libpqxx/7.10.1/include")
link_directories("/opt/homebrew/Cellar/libpqxx/7.10.1/lib")
include_directories("/opt/homebrew/include")
link_directories("/opt/homebrew/lib")

# ✅ Add your executable
add_executable(qtlearn
        main.cpp
        FrontEnd/MainWindow/PopOutWindow.cpp
        FrontEnd/MainWindow/PopOutWindow.h
        FrontEnd/RegisterLogin/Register/Register.cpp
        FrontEnd/RegisterLogin/Register/Register.h
        BackEnd/DataServerEndPoint/DataServerEndPoint.cpp
        BackEnd/DataServerEndPoint/DataServerEndPoint.h
        BackEnd/DataServerEndPoint/CallserverFastPoint/CallServerFastPoint.cpp
        BackEnd/DataServerEndPoint/CallserverFastPoint/CallServerFastPoint.h
        FrontEnd/MainWindow/RegisterWindow/RegisterWindow.cpp
        FrontEnd/MainWindow/RegisterWindow/RegisterWindow.h
        BackEnd/Tables/LoadTables.cpp
        BackEnd/Tables/LoadTables.h
        BackEnd/DataServerEndPoint/registerUser/RegisterUser.cpp
        BackEnd/DataServerEndPoint/registerUser/RegisterUser.h
        BackEnd/DataServerEndPoint/registerUser/PasswordHash/PasswordHash.cpp
        BackEnd/DataServerEndPoint/registerUser/PasswordHash/PasswordHash.h
        BackEnd/DataServerEndPoint/LoginChecker/LoginChecher.cpp
        BackEnd/DataServerEndPoint/LoginChecker/LoginChecher.h
)

# ✅ Link libraries
target_include_directories(qtlearn PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(qtlearn
        PRIVATE
        Qt6::Widgets
        pq
        pqxx
        OpenSSL::Crypto
)

# ✅ Set runtime paths for dynamic libraries
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "/opt/homebrew/Cellar/libpqxx/7.10.1/lib;/opt/homebrew/opt/libpq/lib;/opt/homebrew/opt/openssl@3/lib")