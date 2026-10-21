#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_84458(void*, int);
extern "C" char lbl_27_data_26028[];
extern "C" void* getInstance__13soEventSystemFv();

class EventManager {
public:
    virtual void unused();
    virtual void remove(s32);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, long);

extern "C" void* fn_27_1E4620(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84458, 0xc, 7);
        }
        if (self && self) {
            *(void**)self = lbl_27_data_26028;
            if (*(s16*)((u8*)self + 0x4) != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EventManager* mgr = getManager__13soEventSystemFl(
                    inst, *(s16*)((u8*)self + 0x4));
                mgr->remove(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
