#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_27_84198(void* p, int n);
extern "C" char lbl_27_data_25948[];
extern "C" void* getInstance__13soEventSystemFv(void);
extern "C" void* getManager__13soEventSystemFl(void* self, long idx);

class EvMgr {
public:
    virtual void v0();
    virtual void v3(long arg);
};

extern "C" void* fn_27_18D498(void* p, s32 del) {
    if (p) {
        if ((u8*)p + 0xc != 0) {
            if ((u8*)p + 0x1c != 0) {
                __destroy_arr((u8*)p + 0x28, fn_27_84198, 0xc, 5);
            }
        }
        if (p && p) {
            s16 idx = *(s16*)((u8*)p + 0x4);
            *(void**)p = lbl_27_data_25948;
            if (idx != -1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)p + 0x4));
                mgr->v3(*(s16*)((u8*)p + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
