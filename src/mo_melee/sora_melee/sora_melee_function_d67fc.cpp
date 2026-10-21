#include <types.h>
#pragma force_active on

extern "C" void fn_27_84458(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26028[];

struct EventManager {
    virtual void unused0();
    virtual void remove(int);
};

extern "C" void* fn_27_D67FC(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0x0C && (u8*)self + 0x1C) {
            __destroy_arr((u8*)self + 0x28, fn_27_84458, 0x0C, 0x16);
        }

        if (self != 0 && self != 0) {
            s16 id = *(s16*)((u8*)self + 4);
            *(void**)self = lbl_27_data_26028;
            if (id != -1) {
                EventManager* manager = (EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 4));
                manager->remove(*(s16*)((u8*)self + 6));
            }
        }

        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
