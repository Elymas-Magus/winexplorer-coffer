#ifndef COFFER_H
#define COFFER_H
#include <iostream>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>

using std::string;
class Coffer
{
    private:
        string path;

    protected:

    public:
        Coffer(string path) {
            this->path = path;
        }
        bool check() {
            return this->checkDir(this->path);
        }
        bool checkDir(string path) {
            DIR * dir = this->findDir(path);
            return dir != NULL;
        }
        DIR * findDir(string path) {
            return opendir(path.c_str());
        }
        bool hasCoffer() {
            bool isLocked = this->isLocked();
            bool isUnlocked = this->isUnlocked();

            return isLocked || isUnlocked;
        }
        bool isLocked() {
            return this->checkDir(this->path + "/Locked");
        }
        bool isUnlocked() {
            return this->checkDir(this->path + "/Private");
        }
        bool lock() {
            int hide = NULL, status = NULL;

            hide = system(
              this->getRenameCommand("Private", "Locked").c_str()
            );

            if (hide != 0) {
                return false;
            }

            status = system(
                this->getLockerCommand().c_str()
            );

            if (hide == 0 && status == 0) {
                printf("Cofre trancado");
                return true;
            }

            return false;
        }
        bool unlock() {
            int hide = NULL, status = NULL;

            status = system(
                this->getUnlockerCommand().c_str()
            );

            if (status != 0) {
                return false;
            }

            hide = system(
              this->getRenameCommand("Locked", "Private").c_str()
            );

            if (hide == 0 && status == 0) {
                printf("Cofre destrancado");
                return true;
            }

            return false;
        }
        string getUnlockerCommand() {
            return "attrib -h -s " + this->path + "\\Locked";
        }
        string getLockerCommand() {
            return "attrib +h +s " + this->path + "\\Locked";
        }
        string getRenameCommand(string suffix_1, string suffix_2) {
            suffix_1 = this->path + "\\" + suffix_1;
            return "ren " + suffix_1 + " " + suffix_2;
        }
        void toggle() {
            if (!this->hasCoffer()) {
                return;
            } else if (this->isLocked()) {
                this->unlock();
            } else if (this->isUnlocked()) {
                this->lock();
            }
        }
};

#endif // COFFER_H
