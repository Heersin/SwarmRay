//
// Created by heersin on 1/26/21.
//

#include "CmdParser.h"

CmdParser::CmdParser() : opts("SwarmRay"), vm()
{
    // variable stored here
    config_path = "./ray.conf";

    opts.add_options()
            ("help,h", "help info")
            ("config,c", value<string>(), "specify config file")
            ("target,t", value<vector<string>>()->multitoken()->required(), "targetet scan file")
            ;
}

bool CmdParser::parse(int argc, char **argv)
{
    try{
        store(parse_command_line(argc, argv, opts), vm);
        notify(vm);
    }
    catch (boost::wrapexcept<boost::program_options::required_option> &e)
    {
        cout << "required a scan target specify by '-t' or '--target' " << endl;
        return false;
    }
    catch (boost::wrapexcept<invalid_command_line_syntax> &e)
    {
        cout << "invalid command" << endl;
        cout << opts << endl;
        return false;
    }
}