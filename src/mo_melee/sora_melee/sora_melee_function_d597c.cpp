#include <types.h>
#pragma force_active on

class soLinkEventObserver;

template <class T>
struct soInstanceUnitFullProperty {
    char d[12];
    ~soInstanceUnitFullProperty();
};

struct Holder {
    char pad[12];
    soInstanceUnitFullProperty<soLinkEventObserver*> arr[2];
};

struct Outer {
    char pad[16];
    Holder h;
};

struct Whole {
    char pad[12];
    Outer o;
};

template <class T>
struct soEventUnitWrapper {
    static char __vt[];
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

extern "C" void* fn_27_D597C(Whole* p, s16 flag) {
    if (p) {
        p->o.~Outer();
        if (p != 0 && p != 0) {
            s16 id = *(s16*)((char*)p + 4);
            *(void**)p = (void*)soEventUnitWrapper<soLinkEventObserver>::__vt;
            if (id != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((char*)p + 4)))->fn1(*(s16*)((char*)p + 6));
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
