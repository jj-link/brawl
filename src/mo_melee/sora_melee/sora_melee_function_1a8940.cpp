#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void* fn_27_840D8(void*, int);

class soTurnEventObserver;

template<class T>
class soEventUnitWrapper {
public:
    static char __vt[];
};

class EvMgr {
public:
    virtual void v0();
    virtual void remove(short);
};

extern "C" void* fn_27_1A8940(void* arg0, s32 flag) {
    if (arg0 != NULL) {
        if ((u8*)arg0 + 0xc) {
            if ((u8*)arg0 + 0x1c) {
                __destroy_arr((u8*)arg0 + 0x28,
                              (void (*)(void*, int))fn_27_840D8, 0xc, 4);
            }
        }
        if (arg0 && arg0) {
            short id = *(s16*)((u8*)arg0 + 4);
            *(void**)arg0 = soEventUnitWrapper<soTurnEventObserver>::__vt;
            if (id != -1) {
                ((EvMgr*)getManager__13soEventSystemFl(
                     getInstance__13soEventSystemFv(),
                     *(s16*)((u8*)arg0 + 4)))
                    ->remove(*(s16*)((u8*)arg0 + 6));
            }
        }
        if (flag > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
