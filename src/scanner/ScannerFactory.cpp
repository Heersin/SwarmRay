//
// Created by heersin on 1/30/21.
//

#include "ScannerFactory.h"

BaseScanner ScannerFactory::product(BUILTIN_SCANNER_NAME scanner_name, BUILTIN_SCANNER_TYPE scanner_type)
{
    if(scanner_type == SEARCH)
        return searchProduct(scanner_name);
    else
        return syntaxProduct(scanner_name);
}