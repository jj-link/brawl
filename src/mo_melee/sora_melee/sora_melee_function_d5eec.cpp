#include <types.h>
#pragma force_active on

extern "C" void fn_27_84518(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_26078[];

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_D5EEC(void* p, s32 flag) {
    if (p) {
        if ((u8*)p + 0xC != 0 && (u8*)p + 0x1C != 0) {
            __destroy_arr((u8*)p + 0x28, fn_27_84518, 0xC, 1);
        }
        if (p && p) {
            s16 id = *(s16*)((u8*)p + 4);
            *(void**)p = (void*)lbl_27_data_26078;
            if (id != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((u8*)p + 4)))->fn1(*(s16*)((u8*)p + 6));
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
