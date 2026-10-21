#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_6880C(void*, short);
void __dl__FPv(void*);
}

struct IEvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s32 id);
};

struct IEvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16 a, s16 b);
};

struct fn27Obj {
    char pad[8];
    void* vtbl;
    s16 m_c;
    s16 m_e;
    s16 m_10;
};

extern "C" fn27Obj* fn_27_689B0(fn27Obj* p, s32 flag) {
    if (p != nullptr) {
        if (((char*)p + 8 != nullptr) && ((char*)p + 8 != nullptr)) {
            s16 id = p->m_c;
            p->vtbl = (void*)&soEventObserver<soAnimCmdEventObserver>::__vt;
            IEvSys* inst = (IEvSys*)getInstance__13soEventSystemFv();
            u32 r = inst->f6(id);
            if (r == 1U) {
                IEvMgr* mgr = (IEvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->m_c);
                mgr->f3(p->m_e, p->m_10);
            }
            p->m_10 = -1;
            p->m_c = -1;
        }
        fn_27_6880C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
