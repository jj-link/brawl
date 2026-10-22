#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

class soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

struct EvSys {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual u32 s8(s32 id);
};

struct EvMgr {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void f5(s16 a, s16 b);
};

struct CtlObj {
    void* pad0;
    void* vt;
    s16 m8;
    s16 mA;
    s16 mC;
};

extern "C" void* fn_27_69684(void* p, s32 flag) {
    if (p != nullptr) {
        CtlObj* c = (CtlObj*)p;
        if ((char*)p + 4 != nullptr && (char*)c + 4 != nullptr) {
            s16 id = c->m8;
            c->vt = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->s8(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), c->m8);
                mgr->f5(c->mA, c->mC);
            }
            c->mC = -1;
            c->m8 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
