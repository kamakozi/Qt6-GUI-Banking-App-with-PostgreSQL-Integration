#include "../CallserverFastPoint/CallServerFastPoint.h"
#include "RegisterUser.h"
#include <pqxx/pqxx>
#include <iostream>
#include <random>
bool RegisterUser::insertUser(const QString &username, const QString &password, const QString &email,const QString &countrySelector) {
    try {
        pqxx::connection& conn = CallServerFastPoint::getInstance();

        pqxx::work xtn(conn);


        char alphabet[] = {
            '1', '2', '3', '4', '5',
            '6', '7', '8', '9', '0'};


    std::string stringUsername = username.toStdString();
    std::string stringPassword = password.toStdString();
    std::string stringEmail = email.toStdString();
    std::string countrySel = countrySelector.toStdString();

        std::string Iban= "";
        if (countrySel == "slovenia") {
            Iban = "SL";
        }else if (countrySel == "germany"){
            Iban = "DE";
        }else if (countrySel == "usa") {
            Iban = "US";
        }else if (countrySel == "france") {
            Iban="FR";
        }else if (countrySel == "austria") {
            Iban = "AT";
        }else if (countrySel == "spain") {
            Iban = "ES";
        }else if (countrySel == "united kingdom") {
            Iban = "UK";
        }else if (countrySel == "italy") {
            Iban = "IT";
        }else {
            std::cerr << "Unable to create Iban country code!" << std::endl;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, sizeof(alphabet) - 1);

        for (int i = 0; i < 18; i++) {
            Iban += alphabet[dist(gen)];
        }

        pqxx::result whereCountry = xtn.exec("SELECT id FROM countries WHERE name = " + xtn.quote(countrySel) + " LIMIT 1");
        if (whereCountry.empty()) {
            std::cerr << "Unable to get country" << std::endl;
        }
        int countryId = whereCountry[0][0].as<int>();
        pqxx::result r = xtn.exec("SELECT id FROM roles WHERE name = 'user' LIMIT 1;");
        int roleId = r[0][0].as<int>();
        if (r.empty()) {
            std::cerr << "Unable to get country id" << std::endl;
        }
        std::string query =
            "INSERT INTO users (username, email, password_hash, balance, role_id,country_id,iban) VALUES (" +
            xtn.quote(stringUsername) + ", " +
            xtn.quote(stringEmail) + ", " +
            xtn.quote(stringPassword) + ", " +
            xtn.quote(0.00) + ", " +
            xtn.quote(roleId) +", " +
            xtn.quote(countryId)+ ", " +
            xtn.quote(Iban) + ");";


    xtn.exec(query);
    xtn.commit();
    return true;
    }catch (const std::exception& e) {
        std::cerr << "Database insert failed: " << e.what() << std::endl;
        return false;
    }

}
