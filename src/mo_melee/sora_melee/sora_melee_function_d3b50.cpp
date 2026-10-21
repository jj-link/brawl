#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_21018[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v8(s16 id);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5(s16 a, s16 b);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" Obj* fn_27_D3B50(Obj* p, s32 flags) {
    if (p != nullptr) {
        s16 id = p->m4;
        p->vtbl = lbl_27_data_21018;
        if (((EvSys*)getInstance__13soEventSystemFv())->v8(id) == 1) {
            EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m4);
            mgr->v5(p->m6, p->m8);
        }
        p->m8 = -1;
        p->m4 = -1;
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
