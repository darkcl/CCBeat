//
//  BMSParser.cpp
//  CCBeat
//
//  Created by Yeung Yiu Hung on 14/4/14.
//
//

#include "BMSParser.h"

BMSParser::BMSParser(string fileName){
    bmsFileName = CCString::create(fileName);
}

CCDictionary *BMSParser::parseMetadata(){
    CCDictionary *result = CCDictionary::create();
    result->setObject(CCString::create(BP_VERSION), "BMS_Parser_Version");
    result->setObject(bmsFileName, "filepath");
    result->setObject(CCString::create("text/x-bemusic"), "mime");
    
    return result;
}