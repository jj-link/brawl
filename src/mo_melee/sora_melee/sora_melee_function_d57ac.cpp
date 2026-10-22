#include <types.h>
#pragma force_active on
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
class soLinkEventObserver;
template<class T> struct soInstanceUnitFullProperty {
    char d[0xC];
    ~soInstanceUnitFullProperty();
};
template<class T> struct soEventUnitWrapper {
    static char __vt[];
};
struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};
struct H2 {
    char pad[0xC];
    soInstanceUnitFullProperty<soLinkEventObserver*> arr[1];
    inline ~H2() {}
};
struct H1 {
    char pad[0x10];
    H2 h2;
    inline ~H1() {}
};
struct Outer {
    char p0[0xC];
    H1 h1;
};
extern "C" void* fn_27_D57AC(void* p, s32 flag) {
    if (p) {
        ((Outer*)p)->h1.~H1();
        if (p) {
            if (p) {
                s16 id = *(s16*)((char*)p + 4);
                *(void**)p = (void*)soEventUnitWrapper<soLinkEventObserver>::__vt;
                if (id != -1) {
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)((char*)p + 4)))
                        ->fn1(*(s16*)((char*)p + 6));
                }
            }
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
