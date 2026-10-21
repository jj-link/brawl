#include <types.h>
#pragma force_active on

extern "C" void* fn_27_10E04C(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" char lbl_27_data_26CD0[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_10DE6C(void* arg0, s32 arg1) {
    if (arg0) {
        if ((u8*)arg0 + 0xC != 0 && (u8*)arg0 + 0x1C != 0) {
            __destroy_arr((u8*)arg0 + 0x28, (void (*)(void*, int))fn_27_10E04C, 0xC, 8);
        }
        if (arg0 && arg0) {
            s16 id = *(s16*)((char*)arg0 + 4);
            *(void**)arg0 = (void*)lbl_27_data_26CD0;
            if (id != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((char*)arg0 + 4)))->fn1(*(s16*)((char*)arg0 + 6));
            }
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
