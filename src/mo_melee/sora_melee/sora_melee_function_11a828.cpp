#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_280F8[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_11A828(void* p, s16 flag) {
    if (p) {
        s16 id = *(s16*)((char*)p + 4);
        *(void**)p = (void*)lbl_27_data_280F8;
        if (id != -1) {
            ((EventManager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(s16*)((char*)p + 4)))->fn1(*(s16*)((char*)p + 6));
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
