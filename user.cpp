#include "user.h"

user::user()
{
username = "";
password ="";
}

void user::set_Values(string us, string pass)
{
    username = us ;
    password = pass;
}
