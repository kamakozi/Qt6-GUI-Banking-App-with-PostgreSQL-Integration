cmake_minimum_required(VERSION 3.31)
project(qtlearn)

set(CMAKE_CXX_STANDARD 17)

# Qt setup
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# PostgreSQL / libpqxx paths
include_directories("/opt/homebrew/Cellar/libpqxx/7.10.1/include")
link_directories("/opt/homebrew/Cellar/libpqxx/7.10.1/lib")

include_directories("/opt/homebrew/include")
link_directories("/opt/homebrew/lib")

# ✅ Set RPATH so app finds .dylib files at runtime
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "/opt/homebrew/Cellar/libpqxx/7.10.1/lib;/opt/homebrew/opt/libpq/lib")


# Add executable and all source files
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
)

# Link libraries
target_link_libraries(qtlearn pq pqxx)
target_link_libraries(qtlearn pq pqxx Qt6::Widgets)