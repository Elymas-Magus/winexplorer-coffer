#include <iostream>
#include <cstring>
#include "include/Login.h"
#include "include/Coffer.h"
#include "include/Directory.h"

using namespace std;
typedef long long int big_int;
typedef unsigned long long int u_big_int;

bool validateInput(char * arg1, char * arg2);
string getSelectedPath(char * commandLinePath);

int main(int argc, char * argv[])
{
    Login * sessao;
    Coffer * coffer;

    if (!validateInput(argv[1], argv[2])) {
        exit(1);
    }

    sessao = new Login(string(argv[1]), string(argv[2]));
    if (!sessao->logar()) {
        exit(2);
    }

    coffer = new Coffer(getSelectedPath(argv[3]));
    coffer->toggle();

    return 0;
}

bool validateInput(char * arg1, char * arg2)
{
    return arg1 != NULL && arg2 != NULL;
}

string getSelectedPath(char * commandLinePath)
{
    if (commandLinePath == NULL) {
        return pwd();
    }

    return string(commandLinePath);
}

