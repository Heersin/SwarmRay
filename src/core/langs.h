//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_LANGS_H
#define SWARMRAY_LANGS_H

#include "../scanner/BaseScanner.h"

// TODO Add more Lang Type
enum LANG_TYPE {
    CPP = 0,
    JAVASCRIPT,
    UNKNOWN_LANG};

/* *
 * A dirty and quick hack to fetch name
 * Require: LANG_TYPE * 2 + SCANNER_TYPE = SCANNER_NAME
 * */
BUILTIN_SCANNER_NAME get_scanner_name_by_lang_scanner_type(LANG_TYPE lang, BUILTIN_SCANNER_TYPE type)
{
    int scanner_name_enum_value = lang * 2 + type;
    BUILTIN_SCANNER_NAME scanner_name = static_cast<BUILTIN_SCANNER_NAME>(scanner_name_enum_value);
    return scanner_name;
}


#endif //SWARMRAY_LANGS_H
