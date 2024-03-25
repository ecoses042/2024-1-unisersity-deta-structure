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
        cstudent();
        cstudent(int nId, string strName);
        void set_Name(string strName);
        void set_Id(int nId);
        friend bool operator == (const cstudent& first, const cstudent& second);
        
};

template <class T>

int main()
{
    cstudent soongsil[3];
    for (int i = 0; i < 3 ; i++)
    {
        soongsil[i].get_Id();
        soongsil[i].get_Name();
    }

    return 0;
}

int get_Id()
{
    return m_nId;
}

string get_Name()
{
    return m_strName;
}