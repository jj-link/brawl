#include <types.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);

struct TimerEntry { const char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_80488378[];
extern char lbl_8059EFF8;

struct Heap { u8 pad0[0x14]; u32 f14; u8 pad18[0x10]; u32 f28; };
extern Heap* lbl_805A0EB8;

struct SlotA {
    virtual void s0();
    virtual void s1();
    virtual s32 s4();
};

struct SlotB {
    virtual void s0();
    virtual void s1();
    virtual void s4(void* self);
    u32 f4;
    u32 f8;
};

struct Self {
    u8 pad0[8];
    SlotA* a;
    u8 pad0c[0x44];
    SlotB* b;
};

extern "C" s32 fn_802EE718(Self* self) {
    s32 r = self->a->s4();
    if (r == 0) {
        SlotB* b = self->b;
        if (b != 0 && (s32)(lbl_805A0EB8->f28 + lbl_805A0EB8->f14) > (s32)b->f8) {
            TimerEntry* entry;
            Timer* timer;
            timer = &lbl_80532448;
            entry = timer->current;
            if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
                entry->name = lbl_80488378;
                register u32 t;
                asm { mftb t }
                entry->time = t;
                timer->current = entry + 1;
            }
            b->s4(self);
            TimerEntry* entry2;
            Timer* timer2;
            timer2 = &lbl_80532448;
            entry2 = timer2->current;
            if ((signed char)(((unsigned int)timer2->end << __cntlzw((unsigned int)timer2->end ^ (unsigned int)entry2)) >> 31)) {
                entry2->name = &lbl_8059EFF8;
                register u32 t2;
                asm { mftb t2 }
                entry2->time = t2;
                timer2->current = entry2 + 1;
            }
        }
    }
    return r;
}
