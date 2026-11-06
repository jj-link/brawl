#include <gm/gm_global.h>
#pragma force_active on

struct EventResult {
    u8 cleared : 1;
    u8 flags : 7;
    u8 padding[3];
    u32 score;
};

extern "C" void fn_9_618(u8* self) {
    u8* events;
    gmGlobalRecord::EventHiScoreData* records;
    u8* event;
    u32* scores;
    int i;
    u32 difficulty;
    EventResult* result;
    EventResult* results;
    results = reinterpret_cast<EventResult*>(self + 0x3b0);
    events = self + 0xfb0;
    records = g_GameGlobal->m_record->m_eventHiScoreData;
    for (int mode = 0; mode < 2; ++mode) {
        result = results;
        event = events;
        for (i = 0; i < self[0x13b0]; ++i) {
            scores = reinterpret_cast<u32*>(records);
            for (difficulty = 0; difficulty < 3; ++difficulty) {
                u32 index = event[0xc];
                if ((scores[index] >> 30) > difficulty) {
                    result->cleared = 1;
                } else {
                    result->cleared = 0;
                }
                result->score = scores[index] & 0x3fffffff;
                scores += 51;
                ++result;
            }
            event += 0x10;
        }
        events += 0x404;
        ++records;
        self += 0x404;
        results += 0xc0;
    }
}
