#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_84218(void*, int);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" char lbl_27_data_25F60[];

struct Mgr {
    virtual void f0();
    virtual void f1(s16);
};

extern "C" void* fn_27_D7BEC(void* self, s32 flag) {
    if (self) {
        if ((char*)self + 0xC != 0 && (char*)self + 0x1C != 0) {
            __destroy_arr((char*)self + 0x28, (void (*)(void*, int))fn_27_84218, 0xC, 2);
        }
        if (self && self) {
            s16 id = *(s16*)((char*)self + 4);
            *(void**)self = lbl_27_data_25F60;
            if (id != -1) {
                ((Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((char*)self + 4)))->f1(*(s16*)((char*)self + 6));
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
