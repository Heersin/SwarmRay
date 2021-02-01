#include "app/App.h"
#include "utils/CmdParser.h"
#include "log/ezlog.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[])
{
    App app;
    CmdParser cmdcli;

    // invalid command line
    // TODO start parse
//    if ( !cmdcli.parse(argc, argv))
//        return -1;

    app.run();
}