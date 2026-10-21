#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_26D10[];

struct EvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f5(s16 a, s16 b);
};

struct EvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f8(s16 id);
};

struct EvObj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" EvSys* getInstance__13soEventSystemFv();
extern "C" EvMgr* getManager__13soEventSystemFl(EvSys*, long);
extern "C" void __dl__FPv(void*);

extern "C" EvObj* fn_27_27F3AC(EvObj* p, s32 flag) {
    if (p != nullptr) {
        if (p != nullptr && p != nullptr && p != nullptr) {
            s16 id = p->m4;
            p->vtbl = lbl_27_data_26D10;
            if (getInstance__13soEventSystemFv()->f8(id) == 1) {
                getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m4)->f5(p->m6, p->m8);
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
