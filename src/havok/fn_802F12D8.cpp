#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
struct TimerEntry { const char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_80414030[];
extern char lbl_8059F018;
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
char pad[0x20];
u32 state;
};
extern "C" u32 fn_802F12D8(Object_vptr_0* self) {
    TimerEntry* entry;
    Timer* timer;
    timer = &lbl_80532448;
    entry = timer->current;
    if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
        entry->name = lbl_80414030 + 0x24;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
    if (self->state <= 1U) self->slot3();
    s32 state = self->state;
    if (state == 0 || state == 2) self->slot4();
    TimerEntry* entry2;
    Timer* timer2;
    timer2 = &lbl_80532448;
    entry2 = timer2->current;
    if ((signed char)(((unsigned int)timer2->end << __cntlzw((unsigned int)timer2->end ^ (unsigned int)entry2)) >> 31)) {
        entry2->name = &lbl_8059F018;
        register u32 t2;
        asm { mftb t2 }
        entry2->time = t2;
        timer2->current = entry2 + 1;
    }
    state = self->state;
    if (state == 0 || state == 3) self->slot5();
    return self->state;
}
