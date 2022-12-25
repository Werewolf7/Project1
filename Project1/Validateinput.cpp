#include <string>
#include "Header3.h"

void validate_date(std::string& date) {
    if (date.length() != 10)
        throw "Uncorrect format or uncorrect symbol.";
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '.')
                throw "Uncorrect format or uncorrect symbol.";
        }
        else {
            if (!isdigit(date[i]))
                throw "Uncorrect format or uncorrect symbol.";
        }
    }

    int year, month, day;
    year = stoi(date.substr(0, 4));
    month = stoi(date.substr(5, 2));
    day = stoi(date.substr(8, 2));

    bool isleapyear = 0;
    if (year % 4 == 0)
        isleapyear = 1;
    // int monthwith30days[] = { 4, 6, 9, 11 };
    // int monthwith31days[] = { 1, 3, 5, 7, 8, 10,12 };

    if (year < 1870)
        throw "Error. Year must be more than 1870.";
    if (month > 12 || month < 1)
        throw "Error. Month must be between 1 and 12.";
    if (day < 1)
        throw "Error. Min value of day is 1.";

    if (month == 2 && isleapyear && day > 29)
        throw "Error. This date doesn't exist.";
    else if (month == 2 && !isleapyear && day > 28)
        throw "Error. This date doesn't exist.";
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw "Error. This date doesn't exist.";
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        throw "Error. This date doesn't exist.";
}
void validate_city_code(std::string& code) {
    if (code.length() > 4)
        throw "Code length must be less then 5.";
    if (code.length() < 4) {
        std::reverse(code.begin(), code.end());
        while (code.length() < 4)
            code.push_back('0');
        std::reverse(code.begin(), code.end());
    }

    for (int i = 0; i < 4; i++) {
        if (!isdigit(code[i]))
            throw "Uncorrect symbol. Code can contain only digits.";
    }
}
void validate_city_name(std::string& name) {
    if (name.length() > 15)
        throw "Name length must be less then 16.";

    while (name.length() < 15)
        name.push_back(' ');

    if (!isalpha(name[0]))
        throw "First symbol must be letter.";
    name[0] = toupper(name[0]);

    for (int i = 1; i < 15; i++) {
        if (!isalpha(name[i]) && !isdigit(name[i]) && name[i] != ' ')
            throw "Name must contain only letters and digits.";
        name[i] = tolower(name[i]);
    }
}
void validate_talk_time(std::string& time) {
    if (time.length() > 9 || time.length() < 7)
        throw "Uncorrect format or uncorrect symbol.";

    if (time.length() < 9) {
        std::reverse(time.begin(), time.end());
        while (time.length() < 9)
            time.push_back('0');
        std::reverse(time.begin(), time.end());
    }

    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            if (time[i] != ':')
                throw "Uncorrect format or uncorrect symbol.";
        }
        else {
            if (!isdigit(time[i]))
                throw "Uncorrect symbol.";
        }
    }

    int minuts, seconds;
    minuts = stoi(time.substr(4, 2));
    seconds = stoi(time.substr(7, 2));
    if (minuts > 59)
        throw "Error. Minuts must be between 0 and 59.";
    if (seconds > 59)
        throw "Error. Seconds must be between 0 and 59.";
}
void validate_tariff(std::string& tariff) {
    if (tariff.length() > 14)
        throw "Name length must be less then 15.";

    while (tariff.length() < 14)
        tariff.push_back(' ');

    if (!isalpha(tariff[0]))
        throw "First symbol must be letter.";
    tariff[0] = toupper(tariff[0]);

    for (int i = 1; i < 14; i++) {
        if (!isalpha(tariff[i]) && !isdigit(tariff[i]) && tariff[i] != ' ')
            throw "Tariff must contain only letters and digits.";
        tariff[i] = tolower(tariff[i]);
    }
}
void validate_number(std::string& number) {
    if (number.length() != 12)
        throw "Uncorrect format or uncorrect symbol.";

    for (int i = 0; i < 12; i++) {
        if (!isdigit(number[i]))
            throw "Uncorrect format or uncorrect symbol.";
    }

    /*number.insert(3, 1, ' ');
    number.insert(6, 1, ' ');
    number.insert(10, 1, ' ');
    number.insert(13, 1, ' ');*/
}

int validate_field_number(std::string field_number) {
    if (field_number != "1" && field_number != "2" && field_number != "3" && field_number != "4"
        && field_number != "5" && field_number != "6" && field_number != "7")
        throw "Error. Uncorrect input";

    return stoi(field_number);
}
int validate_choice(std::string choice) {
    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
        throw "Error. Uncorrect input";

    return stoi(choice);
}