#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>

using std::string;

class Login
{
    private:
        string email, password;

    public:
        Login(string email, string password) {
            this->email = email;
            this->password = password;
        }
        bool logar() {
            return true;
        }

    protected:
};

#endif // LOGIN_H
