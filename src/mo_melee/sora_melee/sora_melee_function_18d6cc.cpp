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

extern "C" void* fn_27_18D6CC(void* self, s32 del) {
    if (self != 0) {
        if ((char*)self + 0xC != 0 && (char*)self + 0x1C != 0) {
            __destroy_arr((char*)self + 0x28, fn_27_84458, 0xC, 0x20);
        }
        if (self != 0 && self != 0) {
            s16 id = *(s16*)((char*)self + 4);
            *(void**)self = (void*)lbl_27_data_26028;
            if (id != -1) {
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((char*)self + 4));
                mgr->remove(*(s16*)((char*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
