#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
struct Body;
class Class_804873C8 {
public:
 virtual void fn_802CE6B4();
 virtual void fn_802CEA00();
 virtual void fn_802CE81C();
 virtual void fn_802CE808();
 virtual void fn_802D4AB4();
 virtual void fn_802CE824();
 virtual void fn_802CE928(void*, Body*, void*);
 char pad[0x10];
 Class_804873C8* child;
};
struct Body { Class_804873C8* shape; unsigned int key; unsigned int data; Body* parent; };
struct TimerEntry { char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_804103D0[];
inline void record(int offset) {
    Timer* timer = &lbl_80532448;
    TimerEntry* entry = timer->current;
    if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
        entry->name = lbl_804103D0 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = entry + 1;
    }
}
extern "C" void fn_802CE928(Class_804873C8* self, void* arg1, Body* arg2, void* arg3) {
    record(0);
    Body body;
    body.data = arg2->data;
    body.parent = arg2;
    Class_804873C8* child = self->child;
    body.shape = child;
    body.key = 0;
    child->fn_802CE928(arg1, &body, arg3);
    record(12);
}