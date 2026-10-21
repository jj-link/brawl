#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1180[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

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
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16 a, s16 b);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" Obj* fn_27_10368(Obj* p, s32 flag) {
    if (p) {
        if (p) {
            s16 id = p->m4;
            p->vtbl = lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m4);
                mgr->v3(p->m6, p->m8);
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
