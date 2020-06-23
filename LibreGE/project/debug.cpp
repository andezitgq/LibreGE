#include "debug.h"

Debug::Debug()
{

}

void Debug::Log(string msg){
    cout << "[INFO]    " << msg << endl;
}

void Debug::Inotify(string msg){
    cout << GREEN << "[INOTIFY] " << msg << RESET << endl;
}

void Debug::Error(string msg){
    cout << RED << "[ERROR]   " << msg << RESET << endl;
}

void Debug::Warn(string msg){
    cout << YELLOW << "[WARN]    " << msg << RESET << endl;
}
