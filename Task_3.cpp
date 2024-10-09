#include<iostream>
#include<ctime>
#include<iomanip>

int main() {
    std::tm local_t;
    std::cout << "\nInput time MM:SS : ";
    std::cin >> std::get_time(&local_t, "%M:%S");  
    while (local_t.tm_sec != 0 || local_t.tm_min > 0) {              
        int temp_time = std::time(nullptr);        
         local_t.tm_sec -= 1;
        do {} while ((temp_time) == (std::time(nullptr)));
        std::cout << std::put_time(&local_t, "%M:%S") << std::endl;       
        if (local_t.tm_sec <= 0 && local_t.tm_min != 0) {
            local_t.tm_sec = 60;
            local_t.tm_min--;
        }  
    }
    std::cout << "\nDING! DING! DING!";
}

