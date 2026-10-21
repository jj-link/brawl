#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void fn_27_840D8(void*, int);

class soTurnEventObserver;

template <class T>
struct soEventUnitWrapper {
    static char __vt[];
};

struct EventManager {
    virtual void fn0();
    virtual void fn1(s32);
};

extern "C" void* fn_27_1A8CE0(void* self, s32 del) {
    if (self != 0) {
        if ((u8*)self + 0xc != 0) {
            if ((u8*)self + 0x1c != 0) {
                __destroy_arr((u8*)self + 0x28, fn_27_840D8, 0xc, 7);
            }
        }
        if (self != 0 && self != 0) {
            *(void**)self = soEventUnitWrapper<soTurnEventObserver>::__vt;
            if (*(s16*)((u8*)self + 4) != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                    inst, *(s16*)((u8*)self + 4));
                mgr->fn1(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
