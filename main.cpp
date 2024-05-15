#include <iostream>
#include <vector>
#include <ctime>


void addTask (std::vector<std::string> &report, std::time_t timeStart) {
    std::time_t timeEnd = std::time(nullptr);
    std::time_t duration = std::difftime(timeEnd, timeStart);
    std::string tsk = "task #" + std::to_string(report.size() + 1)
                        + " worktime: " + std::to_string(duration);
    report.push_back(tsk);
}

int main() {
    //24.5.1 time tracker
    // вынести в функцию после timeStart != -1 ...
    std::vector<std::string> report;
    std::time_t timeStart = -1;
    while(true) {
        std::cout << "Command what to do (begin - track new task; end - finish previous task; exit - finish day):" << std::endl;
        std::string command;
        std::cin >> command;
        if (command == "exit") {
            break;
        } else if (command == "begin") {
            if (timeStart != -1) {
                addTask(report, timeStart);
                timeStart = std::time(nullptr);
            } else {
                timeStart = std::time(nullptr);
            }
        } else if (command == "end") {
            if (timeStart != -1) {
                addTask(report, timeStart);
                timeStart = -1;
            }
        } else {
            std::cout  << "Unknown command!" << std::endl;
        }

    }
    if (report.size() > 0) {
        for (auto task : report) {
            std::cout << task << std::endl;
        }
    } else {
        std::cout << "Nothing has been done" << std::endl;
    }
    


}