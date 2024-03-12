// PatientWT.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    int numberOfVisits(0), totalWaitingTime(0);
    char answer;
    while (answer != 'y') 
    {
        bool errorFlag; // arrival, seenByDoctor are instances of Time class
        Time arrival, seenByDoctor;

        cout << "Enter arrival time:";
        arrival.readTime(errorFlag);
        while (errorFlag) 
        {
            cout << "Arrival time was incorrectly formatted; try again: ";
            arrival.readTime(errorFlag);
        }
        cout << "Enter time seen by doctor:";
        seenByDoctor.readTime(errorFlag);
        while (errorFlag) 
        {
            cout << "Seen by doctor time was incorrectly formatted; try again: ";
            seenByDoctor.readTime(errorFlag);
        }
        numberOfVisits++;
        // assume that subtracting one Time from another yields the
            // difference in minutes as an int
        totalWaitingTime += seenByDoctor.subtractTimes(arrival);
        cout << "Done? Enter 'y' to quit, anything else to continue: ";
        cin >> answer;
    } 
    cout << "Number of visits: " << numberOfVisits << "\n";
    cout << "Total waiting time: " << totalWaitingTime << " minutes.\n";
    cout << "Average wait is " << totalWaitingTime / numberOfVisits
        << " minutes.\n";

    int nAvgTime = totalWaitingTime / numberOfVisits;

    Time arrival_new;
    bool errorFlag;

    cout << "Enter arrival time:";
    arrival_new.readTime(errorFlag);
    int expected_time = arrival_new.AddTime(nAvgTime);
    cout << expected_time << endl;
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
