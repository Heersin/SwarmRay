//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_SCANNERFACTORY_H
#define SWARMRAY_SCANNERFACTORY_H
#include "BaseScanner.h"

class AbsScannerFactory {
public:
    virtual JavascriptScanner createJsScanner() = 0;
    virtual CppScanner createCppScanner() = 0;
private:
    // TODO may require more?
};

/*
 * scanner using search techniques
 * A style
 */

class SearchScannerFactory : AbsScannerFactory{
public:
    CppScanner createCppScanner() override;
    JavascriptScanner createJsScanner() override;
};

class SyntaxScannerFactory : AbsScannerFactory{
public:
    CppScanner createCppScanner() override;
    JavascriptScanner createJsScanner() override;
};

#endif //SWARMRAY_SCANNERFACTORY_H