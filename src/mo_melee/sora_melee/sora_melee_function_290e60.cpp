#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26050[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EventManager {
public:
    virtual void slot0();
    virtual void remove(s16);
};

extern "C" void* fn_27_290E60(void* arg0, s32 arg1) {
    if (arg0) {
        if ((u8*)arg0 + 0xc != 0 && (u8*)arg0 + 0x1c != 0) {
            __destroy_arr((u8*)arg0 + 0x28, (void (*)(void*, int))fn_27_84398, 0xC, 0x14);
        }
        if (arg0 && arg0) {
            s16 id = *(s16*)((char*)arg0 + 4);
            *(void**)arg0 = (void*)lbl_27_data_26050;
            if (id != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    *(s16*)((char*)arg0 + 4)))->remove(*(s16*)((char*)arg0 + 6));
            }
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
