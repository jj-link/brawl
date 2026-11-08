#include <types.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);

struct Work {
    unsigned char pad[0x124];
    int active;
};

struct State {
    unsigned char pad0[8];
    Work* work;
    unsigned char padC[4];
    float value;
    unsigned char pad14[8];
    float limit;
    unsigned char pad20[4];
    int field24;
};

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
extern char lbl_80414030[];

extern "C" float fn_802F1184(State*);
extern "C" void fn_802F4B3C(Work*);

inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    TimerEntry* entry = timer->current;

    if ((signed char)(((unsigned int)timer->end
                       << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry))
                      >> 31)) {
        entry->name = lbl_80414030 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}

extern "C" int fn_802F11E0(State* self) {
    self->value = fn_802F1184(self);

    if (self->value >= self->limit && self->work->active != 0) {
        record(0x13);
        fn_802F4B3C(self->work);
        record(0x10);
    }

    self->field24 = 0;
    return 0;
}
