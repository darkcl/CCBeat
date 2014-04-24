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
    
    mixlevels = CCDictionary::create();
    mixlevels->setObject(CCString::create("BASIC"),     "1");
    mixlevels->setObject(CCString::create("NORMAL"),    "2");
    mixlevels->setObject(CCString::create("HYPER"),     "3");
    mixlevels->setObject(CCString::create("ANOTHER"),   "4");
    mixlevels->setObject(CCString::create("INSANE"),    "5");
    
    playTypes = CCDictionary::create();
    playTypes->setObject(CCString::create("Single"),    "1");
    playTypes->setObject(CCString::create("Two"),       "2");
    playTypes->setObject(CCString::create("Double"),    "3");
    
    briefRanks = CCDictionary::create();
    briefRanks->setObject(CCString::create("Very Hard"),    "0");
    briefRanks->setObject(CCString::create("Hard"),         "1");
    briefRanks->setObject(CCString::create("Normal"),       "2");
    briefRanks->setObject(CCString::create("Easy"),         "3");
    
    bmsContent = CCString::createWithContentsOfFile(bmsFileName->getCString());
}

CCDictionary *BMSParser::parseMetadata(){
    CCDictionary *result = CCDictionary::create();
    result->setObject(CCString::create(BP_VERSION), "BMS_Parser_Version");
    result->setObject(bmsFileName, "filepath");
    result->setObject(CCString::create("text/x-bemusic"), "mime");
    
    if (bmsContent != NULL) {
        CCArray *rawBMS = bmsContent->componentsSeparatedByString("\n");
        result->setObject(ccs("100"), "Volume");
        Ref *obj;
        CCARRAY_FOREACH(rawBMS, obj){
            CCString *str = (CCString *)obj;
            string rawStr = str->getCString();
            if (rawStr[0] == '#') {
                string strComp = rawStr.substr(1, rawStr.length()-1);
                CCLOG("%s",strComp.c_str());
                
                CCString *bmsStr = CCString::create(strComp);
                CCArray *metaInfo = bmsStr->componentsSeparatedByString(" ");
                
                if (metaInfo->count() >= 2) {
                    //This line is Meta Info
                    CCString *metaHeader = (CCString *)metaInfo->getObjectAtIndex(0);
                    
                    if ( metaHeader->isEqual(StringMake(B_PLAYTYPE)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "PlayType");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_MUSIC_GENRE)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "Genre");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_SCORE_TITLE)) ) {
                        CCString *titleString = ccs("");
                        if (metaInfo->count() > 3){
                            //Title Contains space, combain string
                            for (int i=1; i<metaInfo->count();i++){
                                if (i==1){
                                    titleString->appendWithFormat("%@", (CCString *)metaInfo->getObjectAtIndex(i));
                                }else{
                                    titleString->appendWithFormat(" %@", (CCString *)metaInfo->getObjectAtIndex(i));
                                }
                            }
                        }else{
                            titleString = (CCString *)metaInfo->getObjectAtIndex(1);
                        }
                        result->setObject(titleString, "MusicTitle");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_MUSIC_ARTIST)) ) {
                        CCString *titleString = ccs("");
                        if (metaInfo->count() > 3){
                            //Title Contains space, combain string
                            for (int i=1; i<metaInfo->count();i++){
                                if (i==1){
                                    titleString->appendWithFormat("%@", (CCString *)metaInfo->getObjectAtIndex(i));
                                }else{
                                    titleString->appendWithFormat(" %@", (CCString *)metaInfo->getObjectAtIndex(i));
                                }
                            }
                        }else{
                            titleString = (CCString *)metaInfo->getObjectAtIndex(1);
                        }
                        result->setObject(titleString, "Artist");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_MUSIC_COARTIST)) ) {
                        CCString *titleString = ccs("");
                        if (metaInfo->count() > 3){
                            //Title Contains space, combain string
                            for (int i=1; i<metaInfo->count();i++){
                                if (i==1){
                                    titleString->appendWithFormat("%@", (CCString *)metaInfo->getObjectAtIndex(i));
                                }else{
                                    titleString->appendWithFormat(" %@", (CCString *)metaInfo->getObjectAtIndex(i));
                                }
                            }
                        }else{
                            titleString = (CCString *)metaInfo->getObjectAtIndex(1);
                        }
                        result->setObject(titleString, "SubArtist");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_MUSIC_BPM)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "BPM");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_SCORE_LEVEL)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "PlayLevel");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_BRIEF_RANK)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "JudgeLevel");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_PARAM_TOTAL)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "GaugeTotals");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_MIXLEVEL)) ) {
                        CCString *key = (CCString *)metaInfo->getObjectAtIndex(1);
                        CCString *diffName = (CCString *)mixlevels->objectForKey(key->getCString());
                        result->setObject(diffName, "Difficulty");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_DET_RANK)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "JudgeRank");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_BGMFILE)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "BackgroundMusic");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_JACKETFILE)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "TitleImage");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_BGAFILE)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "BGAvideo");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(B_VOLUME)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "Volume");
                    }
                    
                    if ( metaHeader->isEqual(StringMake(S_RANDOMIZED)) ) {
                        result->setObject(metaInfo->getObjectAtIndex(1), "RandomizedScore");
                    }
                }
            }
        }
    }
    return result;
}