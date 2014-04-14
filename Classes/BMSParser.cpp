//
//  BMSParser.cpp
//  CCBeat
//
//  Created by Yeung Yiu Hung on 14/4/14.
//
//

#include "BMSParser.h"

BMSParser::BMSParser(string fileName){
    bmsFile.open(fileName);
    if (!bmsFile.good()) {
        throw exception();
    }
}