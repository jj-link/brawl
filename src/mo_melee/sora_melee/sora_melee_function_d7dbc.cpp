#include <types.h>
#pragma force_active on

extern "C" void fn_27_84358(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" char lbl_27_data_21D78[];

struct EvMgr {
    virtual void v0();
    virtual void v1(s16);
};

extern "C" void* fn_27_D7DBC(void* p, s32 flag) {
    if (p) {
        if ((u8*)p + 0xc != 0 && (u8*)p + 0x1c != 0)
            __destroy_arr((u8*)p + 0x28, fn_27_84358, 0xC, 1);
        if (p && p) {
            s16 id = *(s16*)((u8*)p + 4);
            *(void**)p = (void*)lbl_27_data_21D78;
            if (id != -1) {
                ((EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    *(s16*)((u8*)p + 4)))->v1(*(s16*)((u8*)p + 6));
            }
        }
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
