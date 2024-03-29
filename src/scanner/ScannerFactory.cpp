//
// Created by heersin on 1/30/21.
//

#include "ScannerFactory.h"
JavascriptScanner SyntaxScannerFactory::createJsScanner()
{
    JavascriptScanner scanner;
    add_js_feature(scanner);

    printf("Creating Js Syntax Scanner ...\n");
    return scanner;
}

JavascriptScanner SearchScannerFactory::createJsScanner()
{
    JavascriptScanner scanner;
    register_search_engine(scanner);

    printf("Creating Js search Scanner ...\n");
    return scanner;
}

CppScanner SyntaxScannerFactory::createCppScanner()
{
    CppScanner scanner;
    add_cpp_feature(scanner);

    printf("Creating Cpp Syntax Scanner ...\n");
    return scanner;
}

CppScanner SearchScannerFactory::createCppScanner()
{
    CppScanner scanner;
    register_search_engine(scanner);

    printf("Creating Cpp Search Scanner ...\n");
    return scanner;
}
