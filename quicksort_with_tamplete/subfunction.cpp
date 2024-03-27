#include "qs.h"

int cstudent::get_Id()
{
    return m_nId;
}

string cstudent::get_Name()
{
    return m_strName;
}

void cstudent::set_Name(string strName)
{
    m_strName = strName;
}

void cstudent::set_Id(int nId)
{
    m_nId = nId;
}

bool operator ==(cstudent& first, cstudent& second)
{
    return (first.get_Id() == second.get_Id());
}