#ifndef QS_H
#define QS_H

#include <iostream>
#include <string>

using namespace std;

class cstudent{
    private:
        int m_nId;
        string m_strName;
    public:
        int get_Id();
        string get_Name();
        cstudent(int m_nId, string m_strName);
        void set_Name(string strName);
        void set_Id(int nId);
        friend bool operator == (const cstudent& first, const cstudent& second);
        
};

template <class T>
void quick_sort(T a[], int first, int last);
template <class T>
int partition(T a[],int lastsmall, int last);
template <class T>
void print_array(T a[], int size);


#endif