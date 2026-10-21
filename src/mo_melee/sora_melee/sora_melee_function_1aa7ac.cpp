#include <types.h>
#pragma force_active on
extern "C" void fn_27_844D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_260C8[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EvMgr {
public:
    virtual void f0();
    virtual void f1(int);
};

extern "C" void* fn_27_1AA7AC(void* self, int del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_844D8, 0xc, 0xa);
        }
        if (self && self) {
            s16 idx = *(s16*)((u8*)self + 0x4);
            *(char**)self = lbl_27_data_260C8;
            if (idx != -1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 0x4));
                mgr->f1(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
