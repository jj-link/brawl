#include <types.h>
#pragma force_active on

extern "C" void fn_27_84458(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26028[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EvMgrBase {
public:
    virtual void v0();
    virtual void f1(s32 a);
};

extern "C" void* fn_27_1A9D88(void* self, s32 del) {
    if (self) {
        if (((u8*)self + 0xc) != 0 && ((u8*)self + 0x1c) != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84458, 0xc, 0x12);
        }
        if (self && self) {
            s16 id = *(s16*)((u8*)self + 0x4);
            *(void**)self = lbl_27_data_26028;
            if (id != -1) {
                EvMgrBase* mgr = (EvMgrBase*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 0x4));
                mgr->f1(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
