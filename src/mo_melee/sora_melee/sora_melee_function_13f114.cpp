#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_2A924[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct EvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f5(s16 a, s16 b);
    virtual void f6();
    virtual void f7();
    virtual u32 f8(s32 id);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" Obj* fn_27_13F114(Obj* p, s32 flag) {
    if (p != nullptr) {
        s16 id = p->m4;
        p->vtbl = lbl_27_data_2A924;
        if (((EvMgr*)getInstance__13soEventSystemFv())->f8(id) == 1) {
            EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m4);
            mgr->f5(p->m6, p->m8);
        }
        p->m8 = -1;
        p->m4 = -1;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
