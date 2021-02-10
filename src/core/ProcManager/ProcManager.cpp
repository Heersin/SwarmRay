//
// Created by heersin on 1/31/21.
//

#include "ProcManager.h"
#include <Python.h>
void ProcManager::launchProc(EXTERN_COMMAND command, vector<string> &args) {
    switch (command)
    {
        case PYTHON_PLUGIN:
            this->launchPythonProc(args);
            break;

        case WEB_SERVER:
            this->launchWebProc(args);
            break;

        default:
            break;
    }
}

void ProcManager::launchPythonProc(vector<string> &args)
{
    int argc = args.size();
    wchar_t** argv = (wchar_t **)PyMem_Malloc(sizeof(wchar_t*)*argc);
    for (int i=0; i<argc; i++) {
        wchar_t* arg = Py_DecodeLocale(args[i].c_str(), NULL);
        argv[i] = arg;
    }
    Py_Initialize();
    PySys_SetArgv(argc, argv);

    printf("[PyManager]Try Launch %s\n", args[0].c_str());

    FILE *plugin_py = fopen(args[0].c_str(), "r");
    PyRun_SimpleFile(plugin_py, reinterpret_cast<const char *>(argv[0]));
    fclose(plugin_py);
    Py_Finalize();
}

/*
 *  Seems A more robust method
 *  source: https://gist.github.com/1901/5684151
 *
 *  std::wstring& to_wstring(std::wstring& dest, std::string const & src)
{
//   std::setlocale(LC_CTYPE, "");
   std::setlocale(LC_CTYPE, "zh_CN");

   size_t const wcs_len = mbstowcs(NULL, src.c_str(), 0);
   std::vector<wchar_t> tmp(wcs_len + 1);
   mbstowcs(&tmp[0], src.c_str(), src.size());

   dest.assign(tmp.begin(), tmp.end() - 1);

   return dest;
}
 */

/* Another one
 *     int argc = args.size();
    const wchar_t **argv = (const wchar_t **)malloc(argc * sizeof(wchar_t *));

    // convert from string to w_chart *
    // not robust, single byte charset only
    for(int i = 0; i < argc; ++i)
    {
        string current_string = args[i];
        wstring tmp_wstring = wstring(current_string.begin(), current_string.end());
        argv[i] = tmp_wstring.c_str();
    }
 * */

void ProcManager::launchTread(BuiltInCommand &command)
{
    printf("launch a thread of builtin Command\n");
    command.exec();
}

void ProcManager::launchWebProc(vector<string> &args) {
    printf("launch a web server\n");
}