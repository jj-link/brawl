#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26050[];

class EventManager {
public:
    virtual void v0();
    virtual void remove(s32);
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" EventManager* getManager__13soEventSystemFl(void*, long);

extern "C" void* fn_27_1A9364(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84398, 0xc, 0xb);
        }
        if (self && self) {
            *(void**)self = lbl_27_data_26050;
            if (*(s16*)((u8*)self + 4) != -1) {
                void* sys = getInstance__13soEventSystemFv();
                EventManager* mgr = getManager__13soEventSystemFl(
                    sys, *(s16*)((u8*)self + 4));
                mgr->remove(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
