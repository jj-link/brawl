#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_840D8(void*, int);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class soTurnEventObserver;

template <class T> struct soEventUnitWrapper {
    static void* __vt[];
};

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_1A8B10(void* self, s32 del) {
    if (self != 0) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_840D8, 0xC, 6);
        }
        if (self != 0 && self != 0) {
            s16 idx = *(s16*)((u8*)self + 0x4);
            *(void**)self = (void*)soEventUnitWrapper<soTurnEventObserver>::__vt;
            if (idx != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    *(s16*)((u8*)self + 0x4)))->fn1(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
