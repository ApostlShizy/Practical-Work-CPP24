#include<iostream>
#include<ctime>
#include<iomanip>

int main() {
    std::tm local_t;
    std::cout << "\nInput time MM:SS : ";
    std::cin >> std::get_time(&local_t, "%M:%S");
    std::time_t s = std::time(nullptr);
    std::tm* local_s = std::localtime(&s);    
    while (local_t.tm_sec != 0 || local_t.tm_min > 0) {              
        int temp_time = local_s->tm_sec;
        do {                        
            std::time_t s = std::time(nullptr);
            std::tm* local_s = std::localtime(&s);
        } while ((temp_time) == (local_s->tm_sec));
        std::cout << std::put_time(&local_t, "%M:%S") << std::endl;        
        local_t.tm_sec -= 1;
        if (local_t.tm_sec <= 0 && local_t.tm_min != 0) {
            local_t.tm_sec = 59;
            local_t.tm_min--;
        }  
    }
    std::cout << "\nDING! DING! DING!";
}

