#include <types.h>
#pragma force_active on
extern "C" void fn_27_84198(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_25948[];
extern "C" void* getInstance__13soEventSystemFv(void);
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EvMgr {
public:
    virtual void v0();
    virtual void v3(s32 x);
};

extern "C" void* fn_27_290760(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84198, 0xc, 2);
        }
        if (self && self) {
            *(void**)self = lbl_27_data_25948;
            if (((s16*)self)[2] != -1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 0x4));
                mgr->v3(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
