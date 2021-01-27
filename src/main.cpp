#include "app/App.h"
#include "utils/CmdParser.h"

int main(int argc, char *argv[])
{
    App app;
    CmdParser cmdcli;

    // invalid command line
    if ( !cmdcli.parse(argc, argv))
        return -1;

    app.run();
}