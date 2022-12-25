#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <filesystem>
#include "Header3.h"

const int AMOUNT = 10;
HINSTANCE Load = LoadLibrary(L"MyLibForWorkWithArrOfNum.dll");
typedef long long (*t_1) (long long, std::string);
//t_1 enter_positive_whole_number = (t_1)GetProcAddress(Load, "enter_positive_whole_number");

bool validate_ll(std::string S) {
    int plus_counter = 0, minus_counter = 0;
    long long digit_counter = 0;

    //есть ли в строке лишние символы, сколько '-', '+'
    for (int i = 0; i < S.length(); i++) {
        if (!isdigit(S[i]) && S[i] != '-' && S[i] != '+')
            throw "Invalid symbol";

        if (isdigit(S[i]))
            digit_counter++;
        if (S[i] == '+') plus_counter++;
        if (S[i] == '-') minus_counter++;
        if ((plus_counter + minus_counter) > 1) throw "More then one '+' or '-'";
    }
    if (digit_counter == 0) throw "Number must have at least one digit";

    //проверяем где '+','-'
    if ((plus_counter + minus_counter) == 1) {
        if (S[0] != '+' && S[0] != '-')
            throw "Plus or minus must stay on the first place";
    }

    //проверка на переполнение
    if ((plus_counter + minus_counter) == 1) {
        std::string num = "";
        for (int i = 1; i < S.length(); i++)
            num += S[i];

        if (plus_counter == 1) {
            if (num.length() > 19)
                throw "Long long overflow";
            else if ((num.length() == 19) && (num > "9223372036854775807"))
                throw "Long long overflow";
        }

        if (minus_counter == 1) {
            if (num.length() > 19)
                throw "Long long overflow";
            else if ((num.length() == 19) && (num > "9223372036854775808"))
                throw "Long long overflow";
        }
    }
    else if (S.length() > 19)
        throw "Long long overflow";
    else if ((S.length() == 19) && (S > "9223372036854775807"))
        throw "Long long overflow";

    return 0;
}

long long enter_positive_whole_number(long long limit, std::string message_1) {
    long long N;
    std::string N_str;

    while (1) {
        std::cout << message_1;
        std::cin >> N_str;
        try {
            validate_ll(N_str);
        }
        catch (const char* message) {
            std::cout << message << "\n";
            continue;
        }
        catch (...) {
            std::cout << "Unidentified error" << "\n";
            continue;
        }
        break;
    }
    N = stoll(N_str);
    while ((N < 1) || (N > limit)) {
        std::cout << "You can input number only from 1 to " << limit << ". Please try again.\n";
        while (1) {
            std::cout << message_1;
            std::cin >> N_str;
            try {
                validate_ll(N_str);
            }
            catch (const char* message) {
                std::cout << message << "\n";
                continue;
            }
            catch (...) {
                std::cout << "Unidentified error" << "\n";
                continue;
            }
            break;
        }

        N = stoll(N_str);
    }

    return N;
}
namespace sf = std::filesystem;
class Talk {
private:
    std::string date;
    std::string city_code;
    std::string city_name;
    std::string talk_time;
    std::string tariff;
    std::string caller_number;
    std::string subscriber_number;
public:
    std::string get_date() { return date; }
    std::string get_city_code() { return city_code; }
    std::string get_city_name() { return city_name; }
    std::string get_talk_time() { return talk_time; }
    std::string get_tariff() { return tariff; }
    std::string get_caller_number() { return caller_number; } // кто звонит
    std::string get_subscriber_number() { return subscriber_number; } // кому звонят

    Talk();
    ~Talk() {};
    void print(int i);
    void create();
    void clear();
    void change(int field);
    bool isexist();
    void push(int i);
    void pop(int i);
};
typedef std::pair <Talk*, int> MyPair;

void print_all(MyPair AA);
int binsearch(Talk* list, Talk key, int begin, int end);
void renew(Talk* list, int old_amount, int new_amount);
MyPair insert(Talk* list, int size, int amount, Talk newtalk, int pos);
void create_one(MyPair Records);
void create_several(MyPair Records);
int change(MyPair Records);
MyPair pop_all();
void push_all(MyPair Records, int begin);
void delete_one(MyPair Records);

void menu(MyPair Records) {

    int choice, changed_element;

    choice = input_choice();

    switch (choice) {
    case 1: {
        print_all(Records);
        break;
    }
    case 2: {
        create_one(Records);
        break;
    }
    case 3: {
        create_several(Records);
        break;
    }
    case 4: {
        changed_element = change(Records);
        Records.first[changed_element].push(changed_element);
        break;
    }
    case 5: {
        delete_one(Records);
        break;
    }
    }
}

int main() {
    MyPair Records = pop_all();
    //Talk* list = A.first;
    //int size = A.second;
    //list[0].create();
    //list[0].push(0);
    //list[1].create();
    //list[1].push(1);
        
    //for (int i = 0; i < 2; i++) {
    //    list[i].create();
    //    list[i].push(i);
    //}


    while (1) {
        try {
            //A = menu(list, size);
            //list = A.first;
            //size = A.second;
            menu(Records);
        }
        catch (const int) {
            std::cout << "Unable to open file.\n";
            return EXIT_FAILURE;
        }
    }

    delete[] Records.first;

    return 0;
}

Talk::Talk() {
    date = "?";
    city_code = "?";
    city_name = "?";
    talk_time = "?";
    tariff = "?";
    caller_number = "?";
    subscriber_number = "?";
}
void Talk::print(int i) {
    std::cout << "|| " << std::setw(2) << i << " | "
        << date << " | "
        << city_code << "      | "
        << city_name << " | "
        << talk_time << " | "
        << tariff << " | +"
        << caller_number << "     | +"
        << subscriber_number << "     ||\n";
}
void Talk::create() {
    //std::string test_data = input_date();
    date = input_date();

    //std::string test_city_code = input_city_code();
    city_code = input_city_code();

    //std::string test_city_name = input_city_name();
    city_name = input_city_name();

    //std::string test_talk_time = input_talk_time();
    talk_time = input_talk_time();

    //std::string test_tariff = input_tariff();
    tariff = input_tariff();

    //std::string test_caller_number = input_number(0);
    caller_number = input_number(0);

    //std::string test_subscriber_number = input_number(1);
    subscriber_number = input_number(1);
}
void Talk::clear() {
    date = "?";
    city_code = "?";
    city_name = "?";
    talk_time = "?";
    tariff = "?";
    caller_number = "?";
    subscriber_number = "?";
}
void Talk::change(int field) {
    switch (field) {
    case 1: {
        std::string new_date = input_date();
        date = new_date;
        break;
    }
    case 2: {
        std::string new_city_code = input_city_code();
        city_code = new_city_code;
        break;
    }
    case 3: {
        std::string new_city_name = input_city_name();
        city_name = new_city_name;
        break;
    }
    case 4: {
        std::string new_talk_time = input_talk_time();
        talk_time = new_talk_time;
        break;
    }
    case 5: {
        std::string new_tariff = input_tariff();
        tariff = new_tariff;
        break;
    }
    case 6: {
        std::string new_caller_number = input_number(0);
        caller_number = new_caller_number;
        break;
    }
    case 7: {
        std::string new_subscriber_number = input_number(1);
        subscriber_number = new_subscriber_number;
        break;
    }
    }
}
bool Talk::isexist() {
    if (date == "?" && city_code == "?" && city_name == "?" && talk_time == "?"
        && tariff == "?" && caller_number == "?" && subscriber_number == "?")
        return false;
    return true;
}
void Talk::push(int i) {
    std::fstream file("file.bin", std::ios::binary | std::ios::app);
    if (!file.is_open())
        throw 0;
    std::cout << "before: " << file.tellp() << "\n";
    file.seekp(i * sizeof(*this), std::ios::beg);
    std::cout << "after: " << file.tellp() << "\n";

    file.write((char*)this, sizeof(*this));
    file.close();
}
void Talk::pop(int i) {
    std::ifstream file("file.bin", std::ios::binary);
    if (!file.is_open())
        throw 0;
    file.seekg(i * sizeof(*this), std::ios::beg);
    file.read((char*)this, sizeof(*this));
    file.close();
}

void print_all(MyPair AA) {
    int counter = 0;
    std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| No | Date       | City code | City name       | Talk time | Tariff         | Caller number     | Subscriber number ||\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < AA.second; i++) {
        if (AA.first[i].isexist()) {
            AA.first[i].print(i + 1);
            counter++;
        }
    }
    if (!counter)
        std::cout << "||                                                     No records                                                     ||\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
}
int binsearch(Talk* list, Talk key, int begin, int end) {
    if (begin == end - 1) return begin;
    int mid = (begin + end) / 2;
    if (key.get_date() < list[mid].get_date())
        return binsearch(list, key, begin, mid);
    else
        return binsearch(list, key, mid, end);
}
void renew(Talk* list, int old_amount, int new_amount) {
    Talk* new_list = new Talk[new_amount];
    for (int i = 0; i < old_amount; i++) {
        new_list[i] = list[i];
    }
    delete[] list;
    list = new_list;
    //return new_list;
}
void insert(MyPair Records, int amount, Talk newtalk, int pos) {
    int size = Records.second;
    Talk* list = Records.first;

    if (amount == size) {
        size += AMOUNT;
        renew(list, amount, size);
    }
    for (int i = amount - 1; i >= pos; i--) {
        list[i + 1] = list[i];
    }
    list[pos] = newtalk;
}
void create_one(MyPair Records) {
    Talk newtalk;
    newtalk.create();

    int size_records = Records.second;

    Talk newtalk_date, list_last_date, list_first_date;
    int amount; // amount of existing elements
    for (amount = 0; amount < size_records; amount++) {
        if (!Records.first[amount].isexist()) {
            break;
        }
    }

    int pos;
    if (amount == 0) {
        pos = 0;
    }
    else {
        newtalk_date = newtalk;
        list_last_date = Records.first[amount - 1];
        list_first_date = Records.first[0];

        if (newtalk_date.get_date() >= list_last_date.get_date())
            pos = amount;
        else if (newtalk_date.get_date() <= list_first_date.get_date())
            pos = 0;
        else
            pos = binsearch(Records.first, newtalk, 0, amount - 1);
    }
    insert(Records, amount, newtalk, pos);
    push_all(Records, pos);
}
void create_several(MyPair Records) {
    int amount_of_new_records = enter_positive_whole_number(100, "Enter the amount of records you want to enter: ");

    for (int i = 0; i < amount_of_new_records; i++) {
        create_one(Records);
    }
}
int change(MyPair Records) {
    Talk* list = Records.first;
    int size = Records.second;

    int field_number, talk_number;
    int amount; // amount of existing elements
    std::string talk_number_str;

    for (amount = 0; amount < size; amount++) {
        if (!list[amount].isexist())
            break;
    }
    if (amount == 0) {
        std::cout << "No records.\n";
        return 0;
    }
    std::cout << "Choose # talk:\n";
    print_all(Records);
    talk_number = (int)enter_positive_whole_number(amount, "Enter # talk: ");
    field_number = input_field_number();
    list[talk_number - 1].change(field_number);
    list[talk_number - 1].push(talk_number - 1);
    print_all(Records);
    return talk_number - 1;
}
MyPair pop_all() {
    int famount = sf::file_size("file.bin") / 280;
    int size = ((famount % AMOUNT) ? (((famount / AMOUNT) + 1) * AMOUNT) : (famount));
    //int size = famount;
    if (size == 0) {
        size += AMOUNT;
        Talk* list = new Talk[size];
        return { list, size };
    }
    Talk* list = new Talk[size];
    for (int i = 0; i < famount; i++) {
        list[i].pop(i);
    }
    return { list, size };
}
void push_all(MyPair Records, int begin) {
    Talk* list = Records.first;
    int size = Records.second;

    int amount; // amount of existing elements
    for (amount = 0; amount < size; amount++) {
        if (!list[amount].isexist())
            break;
    }
    for (int i = begin; i < amount; i++) {
        list[i].push(i);
    }
}
void delete_one(MyPair Records) {
    Talk* list = Records.first;
    int size = Records.second;

    int amount; // amount of existing elements

    for (amount = 0; amount < size; amount++) {
        if (!list[amount].isexist())
            break;
    }
    if (amount == 0) {
        std::cout << "No records.\n";
        return;
    }
    int talk_number = (int)enter_positive_whole_number(amount, "Enter # talk you want to delete: ");

    for (int i = talk_number; i < amount; i++) {
        list[i] = list[i + 1];
    }
    list[amount - 1].clear();

    push_all(Records, talk_number);

    sf::resize_file("file.bin", sf::file_size("file.bin") - 280);
}