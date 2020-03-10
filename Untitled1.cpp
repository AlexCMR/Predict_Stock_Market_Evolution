#include<iostream>
#include <cstring>
using namespace std;
class User
{
private:
    string parola;
    int suma;
    string adress;
public:
    string nume;
    User(string a ,string b ,int c, string d)
    {
        this->parola = b;
        this->nume = a;
        this->suma = c;
        this->adress=d;
    };
    User sign_up(string a,string b, int c, string d )
    {
        User(a , b, c, d);

    };
    bool login(string a, string b)
    {
        if(this->nume==b && this->parola==a )
            return true;
        else
            return false;
    };
    void verification(string a, string b, User *p)
    {
        int i;
        bool m;
        char d;
        int cod;
        while(p[i].nume!=NULL && i<=9999)
        {
            m = p[i].login(a , b);
            if(m == 1)
                break;

            else
                this->sign_up(a , b, c, d);
        }
    };
};
int main()
{
    User *p;
    p= new User(20);
}
