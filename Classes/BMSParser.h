//
//  BMSParser.h
//  CCBeat
//
//  Created by Yeung Yiu Hung on 14/4/14.
//
//

#ifndef __CCBeat__BMSParser__
#define __CCBeat__BMSParser__

#include <iostream>
#include "cocos2d.h"

#include <fstream>
#include <cstring>

using namespace std;
using namespace cocos2d;

static const string BP_VERSION         ="0.1";
static const string B_PLAYTYPE         ="PLAYER";      // Play mode
static const string B_MUSIC_GENRE      ="GENRE";       // Music genre
static const string B_SCORE_TITLE      ="TITLE";       // Music title
static const string B_MUSIC_ARTIST     ="ARTIST";      // Music Artist
static const string B_MUSIC_COARTIST   ="SUBARTIST";   // Music co-artist
static const string B_MUSIC_BPM        ="BPM";         // BPM (Beats Per Minute)
static const string B_SCORE_LEVEL      ="PLAYLEVEL";   // Playing Difficulty
static const string B_BRIEF_RANK       ="RANK";        // Judge Level
static const string B_PARAM_TOTAL      ="TOTAL";       // Gauge Totals
static const string B_MIXLEVEL         ="DIFFICULTY";  // Display difficulty name
static const string B_DET_RANK         ="DEFEXRANK";   // Judge Rank (detailed)
static const string B_BGMFILE          ="MIDIFILE";    // Name of Background Music file
static const string B_JACKETFILE       ="STAGEFILE";   // Name of Title Image file.
static const string B_BGAFILE          ="VIDEOFILE";   // Name of BGA video file.
static const string B_VOLUME           ="VOLWAV";      // Sound Volume
static const string S_RANDOMIZED       ="RANDOM";      // main directive for randomized score

// Maximum channel numbers
static const int SP5KEYS   =16; // Single Play (5 keys) / 11~15: Keys 1~5, 16: SC
static const int SP7KEYS   =19; // Single Play (7 keys) / 11~15: Keys 1~5, 16: SC, 18~19: Keys 6~7
static const int DP9KEYS   =25; // Double Play (9 keys) / 11~15: Keys 1~5, 22~25: Keys 6~9
static const int DP10KEYS  =26; // Double Play (10 keys) / 11~15: 1P Keys 1~5, 16: 1P SC, 21~25: 2P Keys 1~5, 26: 2P SC
static const int DP14KEYS  =29; // Double Play (14 keys) / 11~15: 1P Keys 1~5, 16: 1P SC, 18~19: 1P Keys 6~7, 21~25: 2P Keys 1~5, 26: 2P SC, 28~29: 2P Keys 6~7
// for Long-notes (standard notes + 40)
static const int LN_SP5KEYS    =56;
static const int LN_SP7KEYS    =59;
static const int LN_DP9KEYS    =65;
static const int LN_DP10KEYS   =66;
static const int LN_DP14KEYS   =69;
// For BM98
static const int APP1_SP5KEYS  =15;
static const int APP2_SP5KEYS  =17; // Pedal-1
// For right-side Play
static const int RP_SINGLEPLAY =21;
static const int RP_SP5KEYS    =26; // Single Play (5 keys) / 21~25: Keys 1~5, 26: SC
static const int RP_SP7KEYS    =29; // Single Play (7 keys) / 21~25: Keys 1~5, 26: SC, 28~29: Keys 6~7
// Channel number for scratch notes
static const int SCR_LEFT      =16;
static const int SCR_RIGHT     =26;
static const int LN_SCR_LEFT   =56;
static const int LN_SCR_RIGHT  =66;

class BMSParser{
    
    public:
        BMSParser(string fileName);
        CCDictionary *parseMetadata();
    private:
        ifstream bmsFile;
};

#endif /* defined(__CCBeat__BMSParser__) */

