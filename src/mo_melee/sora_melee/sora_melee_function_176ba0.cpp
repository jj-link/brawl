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

struct fn27Obj {
    void* vptr;
    void* vt4;
    s16 m_8;
    s16 m_A;
    s16 m_C;
};

struct fn27Vt {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual s32 f8(s16 a);
};

struct fn27Mgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f5(s16 a, s16 b);
};

extern "C" fn27Obj* fn_27_176BA0(fn27Obj* p, s32 flag) {
    if (p != nullptr) {
        if (p != nullptr) {
            if (&p->vt4 != nullptr && &p->vt4 != nullptr) {
                s16 id = p->m_8;
                p->vt4 = soEventObserver<soGimmickEventObserver>::__vt;
                u32 r = ((fn27Vt*)getInstance__13soEventSystemFv())->f8(id);
                if (r == 1) {
                    fn27Mgr* mgr = (fn27Mgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), p->m_8);
                    mgr->f5(p->m_A, p->m_C);
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
