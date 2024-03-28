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
        cstudent(int ID = 0, string Name = "") : m_nId(ID), m_strName(Name) {}
        void set_Name(string strName);
        void set_Id(int nId);
        friend bool operator <=(const cstudent& first, const cstudent& second);
};



#endif