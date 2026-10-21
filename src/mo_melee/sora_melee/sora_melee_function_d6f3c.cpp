#include <types.h>
#pragma force_active on

extern "C" void fn_27_84258(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern "C" unsigned char lbl_27_data_25FD8[];

struct EventManager {
    virtual void unused();
    virtual void call(s16);
};

struct EventUnit {
    void* vtable;
    s16 managerID;
    s16 eventID;
};

extern "C" void* fn_27_D6F3C(void* p, s32 del) {
    if (p != 0) {
        if ((u8*)p + 0xC != 0 && (u8*)p + 0x1C != 0) {
            __destroy_arr((u8*)p + 0x28, fn_27_84258, 0xC, 2);
        }

        if (p != 0) {
            if (p != 0) {
                EventUnit* unit = (EventUnit*)p;
                unit->vtable = lbl_27_data_25FD8;
                if (unit->managerID != -1) {
                    void* system = getInstance__13soEventSystemFv();
                    ((EventManager*)getManager__13soEventSystemFl(
                        system, unit->managerID))->call(unit->eventID);
                }
            }
        }

        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
