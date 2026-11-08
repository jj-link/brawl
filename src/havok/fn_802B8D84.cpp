#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern "C" void fn_802B0FE0(int, int, void*, int);
struct TimerEntry {
    char* name;
    u32 time;
    u32 unused;
};
struct Timer {
    u32 unused0;
    TimerEntry* current;
    u32 unused8;
    TimerEntry* end;
    u32 unused10[2];
};
extern Timer lbl_80532448;
extern char lbl_8040FEB8[];
inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    TimerEntry* entry = timer->current;
    if ((signed char)(((unsigned int)timer->end
                       << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry))
                      >> 31)) {
        entry->name = lbl_8040FEB8 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}
extern "C" void fn_802B8D84(int a, int b, void* c, int d) {
    record(10);
    fn_802B0FE0(a, b, c, d);
    record(7);
}