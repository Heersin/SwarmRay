//
// Created by heersin on 1/30/21.
//

#include "ScannerFactory.h"
JavascriptScanner SyntaxScannerFactory::createJsScanner()
{
    JavascriptScanner scanner;
    add_js_feature(scanner);

    printf("Creating Js Scanner ...\n");
    return scanner;
}

