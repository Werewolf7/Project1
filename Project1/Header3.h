#pragma once
#include <string>
void validate_date(std::string& date);
void validate_city_code(std::string& code);
void validate_city_name(std::string& name);
void validate_talk_time(std::string& time);
void validate_tariff(std::string& tariff);
void validate_number(std::string& number);
int validate_field_number(std::string field_number);
int validate_choice(std::string choice);

std::string input_date();
std::string input_city_code();
std::string input_city_name();
std::string input_talk_time();
std::string input_tariff();
std::string input_number(int a /*a = 0 -> caller, a = 1 -> subscriber*/);
int input_field_number();
int input_choice();