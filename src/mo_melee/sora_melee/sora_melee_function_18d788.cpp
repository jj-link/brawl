#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" char lbl_27_data_26050[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EvMgr {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_18D788(void* arg0, s32 arg1) {
    if (arg0) {
        if ((u8*)arg0 + 0xC != 0 && (u8*)arg0 + 0x1C != 0) {
            __destroy_arr((u8*)arg0 + 0x28, (void (*)(void*, int))fn_27_84398, 0xC, 0x10);
        }
        if (arg0 && arg0) {
            s16 id = *(s16*)((u8*)arg0 + 4);
            *(void**)arg0 = (void*)lbl_27_data_26050;
            if (id != -1) {
                ((EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((u8*)arg0 + 4)))
                    ->fn1(*(s16*)((u8*)arg0 + 6));
            }
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
