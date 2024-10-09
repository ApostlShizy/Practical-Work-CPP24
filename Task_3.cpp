#define _CRT_SECURE_NO_WARNINGS

#include<windows.h>
#include<iostream>
#include<ctime>
#include<iomanip>

#if 1
int main() {
    std::time_t s = std::time(nullptr);
    std::tm* local_s = std::localtime(&s);
    std::tm local_t;
    std::cout << "\nInput time MM:SS : ";
    std::cin >> std::get_time(&local_t, "%M:%S");
    while (local_t.tm_sec != 0) {
        std::cout << std::put_time(&local_t, "%M:%S") << std::endl;
        Sleep(1000);
        local_t.tm_sec -= 1;
        if (local_t.tm_sec == 0 && local_t.tm_min != 0) {
            local_t.tm_sec = 59;
            local_t.tm_min--;
        }
    }
    std::cout << "\nDING! DING! DING!";
}
#endif

#if 0
int main() {
    int time = 0;
    {
        int min = 0;
        int sec = 0;
        std::cout << "\nEnter minutes: ";
        std::cin >> min;
        std::cout << "\nEnter second: ";
        std::cin >> sec;
        time = min * 60 + sec;
    }    
    std::time_t s = std::time(nullptr);
    std::tm* local_s = std::localtime(&s);
    
    while (time != 0) {              
        int temp_time = local_s->tm_sec;
        do {                        
            std::time_t s = std::time(nullptr);
            std::tm* local_s = std::localtime(&s);
        } while ((temp_time) == (local_s->tm_sec));
        std::cout << time / 60 << ":" << time % 60 << std::endl;           
        time--;      
    }
    std::cout << "\nDING! DING! DING!";
}
#endif
