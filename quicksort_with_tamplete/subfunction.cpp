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
