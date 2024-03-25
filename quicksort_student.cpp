#include <iostream>
#include <string>

using namespace std;

class cstudent{
    private:
        int m_nId;
        string Namm_strName;
    public:
        int get_Id();
        string get_Name();
        cstudent();
        cstudent(int nId, string strName);
        void set_Name(string strName);
        void set_Id(int nId);
};

int main()
{
    
    return 0;
}