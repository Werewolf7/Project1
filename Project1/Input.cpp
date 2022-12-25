#include <iostream>
#include <string>
#include "Header3.h"

std::string input_date() {
    std::string str;
    while (1) {
        std::cout << "Enter date in the format \"YYYY.MM.DD\": ";
        std::getline(std::cin, str);
        try {
            validate_date(str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    std::string tmp = str;
    return tmp;
}
std::string input_city_code() {
    std::string str;
    while (1) {
        std::cout << "Enter city code: ";
        std::getline(std::cin, str);
        try {
            validate_city_code(str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return str;
}
std::string input_city_name() {
    std::string str;
    while (1) {
        std::cout << "Enter city name: ";
        std::getline(std::cin, str);
        try {
            validate_city_name(str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return str;
}
std::string input_talk_time() {
    std::string str;
    while (1) {
        std::cout << "Enter talk time in the format \"HHH:MM:SS\": ";
        std::getline(std::cin, str);
        try {
            validate_talk_time(str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return str;
}
std::string input_tariff() {
    std::string str;
    while (1) {
        std::cout << "Enter tariff: ";
        std::getline(std::cin, str);
        try {
            validate_tariff(str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return str;
}
std::string input_number(int a /*a = 0 -> caller, a = 1 -> subscriber*/) {
    std::string str;
    while (1) {
        std::cout << "Enter the phone number of " << (!a ? "caller: " : "subscriber: ");
        std::getline(std::cin, str);
        try {
            validate_number(str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return str;
}

int input_field_number() {
    int field_number;
    std::string field_number_str;
    std::cout << "Choose # field:\n";
    std::cout << "1 - date, 2 - city code, 3 - city name, 4 - talk time, 5 - tariff, 6 - number of caller, 7 - number of subscriber\n";
    while (1) {
        std::cout << "Enter # field: ";
        std::getline(std::cin, field_number_str);
        try {
            field_number = validate_field_number(field_number_str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return field_number;
}
int input_choice() {
    int choice;
    std::string choice_str;
    std::cout << "\nChoose what you want: 1 - view content, 2 - create new record,\n\
3 - create a certain amount of records, 4 - change record, 5 - delete record.\n";
    while (1) {
        std::cout << "Enter # : ";
        std::getline(std::cin, choice_str);
        try {
            choice = validate_choice(choice_str);
        }
        catch (const char* message) {
            std::cout << message << '\n';
            continue;
        }
        catch (...) {
            std::cout << "Undefined error.\n";
            continue;
        }
        break;
    }
    return choice;
}