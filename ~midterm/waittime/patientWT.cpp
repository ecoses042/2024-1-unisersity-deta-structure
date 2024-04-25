// PatientWT.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//20211530 송민수 자료구조
#include <iostream>
#include "Time.h"

int main()
{
    int numberOfVisits(0), totalWaitingTime(0);
    char answer;
    bool errorFlag;

    std::cout << "20211530 Minsoo Song\n";
    while (answer != 'y') 
    {
         // arrival, seenByDoctor are instances of Time class
        Time arrival, seenByDoctor;

        std::cout << "Enter arrival time:";
        arrival.readTime(errorFlag);
        while (errorFlag) 
        {
            std::cout << "Arrival time was incorrectly formatted; try again: ";
            arrival.readTime(errorFlag);
        }
        std::cout << "Enter time seen by doctor:";
        seenByDoctor.readTime(errorFlag);
        while (errorFlag) 
        {
            std::cout << "Seen by doctor time was incorrectly formatted; try again: ";
            seenByDoctor.readTime(errorFlag);
        }
        numberOfVisits++;
        // assume that subtracting one Time from another yields the
            // difference in minutes as an int
        totalWaitingTime += seenByDoctor.subtractTimes(arrival);
        std::cout << "Done? Enter 'y' to quit, anything else to continue: ";
        std::cin >> answer;
    }
    Time arrival_new;
    int nAvgTime = totalWaitingTime / numberOfVisits;

    std::cout << "Number of visits: " << numberOfVisits << "\n";
    std::cout << "Total waiting time: " << totalWaitingTime << " minutes.\n";
    std::cout << "Average wait is " << nAvgTime << " minutes.\n";
    std::cout << "Enter arrival time:";
    arrival_new.readTime(errorFlag);

    int expected_time = arrival_new.AddTime(nAvgTime);
    std::cout << "your expected time is:" << expected_time << std::endl;
    
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
