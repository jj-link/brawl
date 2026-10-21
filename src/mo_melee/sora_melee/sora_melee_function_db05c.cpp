#include <types.h>
#pragma force_active on

class soLinkEventObserver;

template <class T>
struct soEventUnitWrapper {
    static char __vt[];
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);

struct Mgr {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_DB05C(void* p, s32 flag) {
    if (p) {
        s16 id = *(s16*)((char*)p + 4);
        *(void**)p = (void*)soEventUnitWrapper<soLinkEventObserver>::__vt;
        if (id != -1) {
            ((Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(),
                *(s16*)((char*)p + 4)))->fn1(*(s16*)((char*)p + 6));
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
