#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16 id);
};

struct EvMgr {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3(s16 x, s16 y);
};

struct Obj {
    char pad0[0x10];
    void* vtbl; // 0x10
    s16 m4;     // 0x14
    s16 m6;     // 0x16
    s16 m8;     // 0x18
};

extern "C" Obj* fn_27_A1E80(Obj* p, s32 flag) {
    if (p) {
        s32 t = (s32)p + 0x10;
        if ((t != 0) && (t != 0)) {
            s16 id = p->m4;
            p->vtbl = (void*)&soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m4);
                mgr->a3(p->m6, p->m8);
            }
            p->m8 = -1;
            p->m4 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
