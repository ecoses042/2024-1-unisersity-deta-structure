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

int main()
{
    
    return 0;
}