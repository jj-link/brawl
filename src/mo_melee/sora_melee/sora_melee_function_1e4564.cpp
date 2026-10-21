#include <types.h>
#pragma force_active on

extern "C" void fn_27_84258(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern "C" unsigned char lbl_27_data_25FD8[];

struct EventManager {
    virtual void v0();
    virtual void call(s16);
};

struct EventUnit {
    void* vtable;
    s16 managerID;
    s16 eventID;
};

extern "C" void* fn_27_1E4564(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84258, 0xC, 1);
        }
        EventUnit* p = (EventUnit*)self;
        if (p && p) {
            p->vtable = lbl_27_data_25FD8;
            if (p->managerID != -1) {
                void* system = getInstance__13soEventSystemFv();
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(system, p->managerID);
                mgr->call(p->eventID);
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
