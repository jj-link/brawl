#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_84358(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
char lbl_27_data_21D78[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
}

struct soEventManager {
    virtual s16 addUnit(void*);
    virtual void eraseObserver(s16);
};

extern "C" void* fn_27_290920(void* self, s32 del) {
    if (self) {
        if ((char*)self + 0xC != 0 && (char*)self + 0x1C != 0) {
            __destroy_arr((char*)self + 0x28, fn_27_84358, 0xC, 2);
        }
        if (self && self) {
            s16 id = *(s16*)((char*)self + 4);
            *(void**)self = (void*)lbl_27_data_21D78;
            if (id != -1) {
                ((soEventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((char*)self + 4)))
                    ->eraseObserver(*(s16*)((char*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
