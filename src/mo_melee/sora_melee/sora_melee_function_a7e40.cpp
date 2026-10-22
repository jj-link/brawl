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
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s32 id);
};

struct EvMgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3(s16 a, s16 b);
};

struct Obj {
    char pad0[8];
    void* vt;
    s16 mC;
    s16 mE;
    s16 m10;
};

extern "C" void* fn_27_A7E40(void* p, s32 flag) {
    if (p != nullptr) {
        Obj* o = (Obj*)p;
        if ((char*)p + 8 != nullptr && (char*)o + 8 != nullptr) {
            s16 id = o->mC;
            o->vt = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->f6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), o->mC);
                mgr->m3(o->mE, o->m10);
            }
            o->m10 = -1;
            o->mC = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
