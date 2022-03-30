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
        bool logar()
            // Regra temporária, implementada no
            // hardcoded apenas para não ficar vazia
            if (this->email != "Elymas-Magus") {
                return false;
            }
            if (this->password != "maguscoffer!@#") {
                return false;
            }

            return true;
        }

    protected:
};

#endif // LOGIN_H
