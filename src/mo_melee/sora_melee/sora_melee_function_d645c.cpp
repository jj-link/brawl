#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int),
                              unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" char lbl_27_data_26050[];

struct EventManager {
    virtual void unused();
    virtual void remove(s32);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, s32);

extern "C" void* fn_27_D645C(void* self, s32 del) {
    if (self != 0) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84398, 0xC, 0xC);
        }

        if (self != 0 && self != 0) {
            s16 id = *(s16*)((u8*)self + 4);
            *(void**)self = lbl_27_data_26050;
            if (id != -1) {
                getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    *(s16*)((u8*)self + 4)
                )->remove(*(s16*)((u8*)self + 6));
            }
        }

        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
