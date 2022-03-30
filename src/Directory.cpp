#include "Directory.h"

string pwd()
{
    char pwd[FILENAME_MAX];

    _getcwd(pwd, sizeof(pwd));

    if (pwd) {
        return string(pwd);
    }

    return NULL;
}
