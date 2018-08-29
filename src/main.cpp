/*
 *  Main gameplay loop
 */


#include "../include/mainloop.h"
using namespace std;

int main (int argc, char *argv[] ) {
    cout << "argc = " << argc << endl;

    for(int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
    MainLoop* ml = new MainLoop();
    ml->tick(argc, argv);
}
