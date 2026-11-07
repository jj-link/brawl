#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
struct TimerEntry { const char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
struct Object { char pad[0x74]; void* child; int state; };
extern Timer lbl_80532448;
extern char lbl_80413438[];
extern "C" void fn_802F66C0(void*);
inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    TimerEntry* entry = timer->current;
    if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
        entry->name = lbl_80413438 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}
extern "C" void fn_802EFE70(Object* self) {
    record(0x303);
    self->state = 0;
    fn_802F66C0(self->child);
    record(0x16);
}