#include "qs.h"

template <class T>

int main()
{
    int int_tempID;
    string string_tempID;

    cstudent soongsil[3];
    for (int i = 0; i < 3 ; i++)
    {
        cout << "enter ID:";
        cin >> int_tempID;
        cout << string_tempID;
        cin >> string_tempID;
        soongsil[i].set_Id(string_tempID);
        soongsil[i].set_Name(string_tempID);
    }


    return 0;
}


