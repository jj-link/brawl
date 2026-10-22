#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

class soGimmickEventObserver;

template <class T>
struct soEventObserver {
    static char __vt[];
};

struct Obj {
    void* pad0;
    void* vtbl;
    s16 m_8;
    s16 m_A;
    s16 m_C;
};

struct EvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f8(s16 a);
};

struct EvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f5(s16 a, s16 b);
};

extern "C" Obj* fn_27_178294(Obj* p, s32 flag) {
    if (p != nullptr) {
        if (p != nullptr) {
            if (&p->vtbl != nullptr && &p->vtbl != nullptr) {
                s16 id = p->m_8;
                p->vtbl = soEventObserver<soGimmickEventObserver>::__vt;
                u32 r = ((EvSys*)getInstance__13soEventSystemFv())->f8(id);
                if (r == 1) {
                    ((EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), p->m_8))
                        ->f5(p->m_A, p->m_C);
                }
                p->m_C = -1;
                p->m_8 = -1;
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
