#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

class soGimmickEventObserver {};

template <class T>
struct soEventObserver {
    static char __vt[];
};

struct Obj {
    s32 pad0;
    void* vtbl;
    s16 m8;
    s16 mA;
    s16 mC;
};

struct EvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s32);
};

struct EvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16, s16);
};

extern "C" Obj* fn_27_1789F0(Obj* p, s32 flag) {
    if (p != nullptr) {
        if (p != nullptr && &p->vtbl != nullptr && &p->vtbl != nullptr) {
            s16 id = p->m8;
            p->vtbl = soEventObserver<soGimmickEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->f6(id) == 1) {
                ((EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->m8))->f3(p->mA, p->mC);
            }
            p->mC = -1;
            p->m8 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
