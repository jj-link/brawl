#include <types.h>
#pragma force_active on

extern "C" void fn_27_84458(void*, int);
extern "C" char lbl_27_data_26028[];
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EvMgr {
public:
    virtual void v0();
    virtual void v1(s32);
    virtual void v2();
    virtual void v3();
};

extern "C" void* fn_27_38F0FC(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84458, 0xc, 0x13);
        }
        if (self != 0 && self != 0) {
            *(void**)self = lbl_27_data_26028;
            if ((s32)*(s16*)((u8*)self + 4) != -1) {
                void* system = getInstance__13soEventSystemFv();
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    system, *(s16*)((u8*)self + 4));
                mgr->v1(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
