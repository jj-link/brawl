#include <types.h>
#pragma force_active on

extern "C" void fn_27_84418(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, s32), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void* getInstance__13soEventSystemFv(void);
extern "C" void* getManager__13soEventSystemFl(void* self, s32 idx);
extern u8 lbl_27_data_26000[];

class EvMgrBase {
public:
    virtual void vf0();
    virtual void vf1(s32 a);
    virtual void vf2();
    virtual void vf3();
};

extern "C" void* fn_27_D6D6C(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, s32))fn_27_84418, 0xc, 1);
        }
        if (self && self) {
            s16 idx = *(s16*)((u8*)self + 0x4);
            *(void**)self = lbl_27_data_26000;
            if (idx != -1) {
                ((EvMgrBase*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 0x4)))->vf1(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
