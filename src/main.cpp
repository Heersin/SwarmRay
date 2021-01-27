#include "app/App.h"
#include "utils/CmdParser.h"

int main(int argc, char *argv[])
{
    App app;
    CmdParser cmdcli;

    cmdcli.parse(argc, argv);
    app.run();
}