#include <types.h>
#pragma force_active on

extern "C" void fn_27_84458(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26028[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_1A9BB8(void* self, s32 flag) {
    if (self) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, int))fn_27_84458, 0xC, 0x11);
        }
        if (self && self) {
            s16 id = *(s16*)((char*)self + 4);
            *(void**)self = (void*)lbl_27_data_26028;
            if (id != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((char*)self + 4)))->fn1(*(s16*)((char*)self + 6));
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
