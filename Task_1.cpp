#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<ctime>
#include<map>

void func_end(std::multimap<std::string, double>& tasks_Map, std::string& task_name, std::time_t& start_t) {
    std::time_t end_t = std::time(nullptr);
    double time = std::difftime(end_t, start_t);
    tasks_Map.insert(std::pair<std::string, double>(task_name, time));
    task_name.clear();
}

int main() {
    std::string task_name;
    std::time_t start;
    std::multimap<std::string, double> tasks_Map;
    std::string choice;
    do {
        std::cout << "\nSelect:\n\nbegin\nend\nstatus\nexit\n\nEnter: ";
        std::cin >> choice;
        if (choice == "begin") {
            if (task_name.empty()) {
                std::cout << "\nTaks name: ";
                std::cin >> task_name;
                start = std::time(nullptr);
            }
            else {
                func_end(tasks_Map, task_name, start);
                std::cout << "\nTaks name: ";
                std::cin >> task_name;
                start = std::time(nullptr);
            }
        }
        else if (choice == "end") {
            if (task_name.empty()) {
                std::cout << "\nDont have eny task now";
            }
            else {
                func_end(tasks_Map, task_name, start);
            }         
        }
        else if (choice == "status") {
            if (!task_name.empty()) {
                std::cout << "\nCurrent task \"" << task_name << "\"";
                std::tm* local = std::localtime(&start);
                std::cout << "\nStartet at: " << asctime(local);
            }
            std::multimap<std::string, double>::iterator iter = tasks_Map.begin();
            if (iter != tasks_Map.end()) {
                for (; iter != tasks_Map.end(); ++iter) {
                    std::cout << "\nCompleted task name \"" << iter->first << "\". Time take: " << iter->second / 3600 << " hour." << std::endl;
                }
            }
            else {
                std::cout << "\nNo completed tasks.";
            }
        }
        else {
            std::cout << "\nWrong input!";
        }
    } while (choice != "exit");
}