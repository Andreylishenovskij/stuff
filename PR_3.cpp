#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
string alphabet = "qQwWeErRtTyYUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm-@_.1234567890";
string letters = "qQwWeErRtTyYUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
bool validation(char c)
{
    for(int i = 0; i < alphabet.size(); i++)
    {
        if( c == alphabet[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{

    string Mail;
    cin>>Mail;
    if(Mail.find_first_of("@") == string::npos)
    {
        cout<<"Wrong domain";
        return 0;
    }
    if(Mail.find_first_of("@") != Mail.find_last_of("@"))
    {
        cout<<"Two '@' are not allowed";
        return 0;
    }
    for(int i = 0;i<Mail.find_first_of("@");i++)
    {
        if(! (validation(Mail[i])))
        {
            cout<<"Wrong symbols used";
            return 0;
        }
    }
    for(int i = 1; i < (Mail.substr(Mail.find_first_of("@"))).size();i++)
    {
        if( Mail.substr(Mail.find_first_of("@")).find_first_of(".") == string::npos)
        {
            cout<<"Wrong domain";
            return 0;
        }
    }
    for(int i = 1; i < (Mail.substr(Mail.find_first_of("@"))).size()-1;i++)
    {
        if( Mail.substr(Mail.find_first_of("@"))[i]  == '.' || Mail.substr(Mail.find_first_of("@"))[i+1]  == '.')
        {
            cout<<"Wrong domain";
            return 0;
        }
    }
    if(Mail[Mail.size()] == '.')
    {
        cout<<"Wrong domain";
        return 0;
    }
    if(Mail[Mail.find_first_of("@")+1] == '.')
    {
      cout<<"Wrong domain";
      return 0;
    }
    


    return 0;
}

