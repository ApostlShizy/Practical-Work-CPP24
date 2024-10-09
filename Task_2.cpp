#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<sstream>

std::string input_date() {
    do {
        std::string date;
        std::cout << "\nEnter date YYYY/MM/DD\nEnter: ";
        std::cin >> date;
        if (date.length() == 10) {
            bool check = true;
            for (int i = 0; i < 10 && check; ++i) {
                if ((i == 4 || i == 7) && date[i] == '/') {
                    continue;
                }
                else if (date[i] < '0' || date[i] > '9') {
                    std::cout << "\nWrong date!!";
                    check = false;
                }               
            }
            if (check) {
                return date;
            }
        }
        else {
            std::cout << "\nWrong input!";
        }
    } while (true);    
}

auto compare = [](const std::tm& t1, const std::tm& t2) {
    if (t1.tm_mon != t2.tm_mon) {
        return t1.tm_mon < t2.tm_mon;
    }
    return t1.tm_mday < t2.tm_mday;
    };

int main() {
    std::map<std::tm, std::vector<std::string>, decltype(compare)> birthDay(compare);
    std::string name;
    do {       
        std::tm buffer_local;
        std::cout << "\nEnter name or \"end\": ";
        std::cin >> name;
        if (name != "end") {
            std::stringstream date (input_date());            
            date >> std::get_time(&buffer_local, "%Y/%m/%d");            
            birthDay[buffer_local].push_back(name);
        }
    } while (name != "end");
    std::time_t today = std::time(nullptr);
    std::tm* today_local = localtime(&today);
    std::cout << "\nNext birthday - ";
    if (birthDay.count(*today_local)) {
        std::map<std::tm, std::vector<std::string>, decltype(compare)>::iterator iter = birthDay.find(*today_local);
        std::cout << "Today !!!: " << iter->first.tm_mon + 1 << "/" << iter->first.tm_mday<<std::endl;
        for (int i = 0; i < iter->second.size(); ++i) {
            std::cout <<"Name: " << iter->second[i] << std::endl;
        }
    }
    else {
        birthDay[*today_local].push_back("");
        std::map<std::tm, std::vector<std::string>, decltype(compare)>::iterator iter = birthDay.find(*today_local);
        iter++;
        if (iter != birthDay.end()) {
            std::cout << "Date: " << iter->first.tm_mon + 1 << "/" << iter->first.tm_mday<<std::endl;
            for (int i = 0; i < iter->second.size(); ++i) {
                std::cout <<"Name: " << iter->second[i] << std::endl;
            }
        }
        else {
            std::cout << " Not find any birthday";
        }
    }
}