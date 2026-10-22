#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_27_84118(void*, int);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern "C" u8 lbl_27_data_44A68[];

struct EvMgr {
    virtual void f0();
    virtual void f1(s16);
};

extern "C" void* fn_27_1AAD74(void* self, s32 del) {
    if (self) {
        if (((u8*)self + 0xC) != 0 && ((u8*)self + 0x1C) != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, int))fn_27_84118, 0xC, 8);
        }
        if (self) {
            if (self) {
                s16 id = *(s16*)((u8*)self + 4);
                *(void**)self = (void*)lbl_27_data_44A68;
                if (id != -1) {
                    ((EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 4)))->f1(*(s16*)((u8*)self + 6));
                }
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
