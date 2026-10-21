#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct EvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s32 id);
};

struct EvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16 a, s16 b);
};

class soGimmickEventObserver;

template<class T>
struct soEventObserver {
    static char __vt[];
};

struct fn27Obj {
    void* unk0;
    void* vptr;
    s16 m_8;
    s16 m_A;
    s16 m_C;
};

extern "C" fn27Obj* fn_27_17881C(fn27Obj* p, s32 flag) {
    if (p != nullptr) {
        if (p != nullptr) {
            if ((char*)p + 4 != nullptr && (char*)p + 4 != nullptr) {
                s16 id = p->m_8;
                p->vptr = soEventObserver<soGimmickEventObserver>::__vt;
                if (((EvSys*)getInstance__13soEventSystemFv())->f6(id) == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), p->m_8);
                    mgr->f3(p->m_A, p->m_C);
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
