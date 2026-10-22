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

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16, s16);
};

struct Obj {
    void* vtbl;
    void* vtbl2;
    s16 m8;
    s16 mA;
    s16 mC;
};

extern "C" Obj* fn_27_177484(Obj* p, s32 flag) {
    if (p != nullptr) {
        if (p != nullptr) {
            if ((char*)p + 4 != nullptr && (char*)p + 4 != nullptr) {
                s16 id = p->m8;
                p->vtbl2 = soEventObserver<soGimmickEventObserver>::__vt;
                if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m8);
                    mgr->v3(p->mA, p->mC);
                }
                p->mC = -1;
                p->m8 = -1;
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
