#include <types.h>
#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_84598(void*, int);
extern "C" char lbl_27_data_25FB0[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class fnEvMgr {
public:
    virtual void vf0();
    virtual void vf1(short);
    virtual void vf2();
    virtual void vf3();
};

extern "C" void* fn_27_D710C(void* self, s32 del) {
    if (self != 0) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, int))fn_27_84598, 0xC, 3);
        }
        if (self != 0 && self != 0) {
            s16 id = *(s16*)((u8*)self + 4);
            *(char**)self = lbl_27_data_25FB0;
            if (id != -1) {
                fnEvMgr* mgr = (fnEvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 4));
                mgr->vf1(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
