
#include "FrontEnd/MainWindow/PopOutWindow.h"
#include "BackEnd/Tables/LoadTables.h"
int main(int argc,char *argv[]) {
        LoadTables lt;
        lt.loadTables();
        PopOutWindow pow;
        return pow.run(argc,argv);
}