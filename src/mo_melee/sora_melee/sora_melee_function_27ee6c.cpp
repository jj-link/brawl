#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_26D10[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);

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

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" Obj* fn_27_27EE6C(Obj* p, s32 flags) {
    if (p != nullptr) {
        if (p != nullptr) {
            if (p != nullptr) {
                if (p != nullptr) {
                    s16 id = p->m4;
                    p->vtbl = lbl_27_data_26D10;
                    if (((EvSys*)getInstance__13soEventSystemFv())->f6(id) == 1) {
                        EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                            getInstance__13soEventSystemFv(), p->m4);
                        mgr->f3(p->m6, p->m8);
                    }
                    p->m8 = -1;
                    p->m4 = -1;
                }
            }
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
