#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_5288[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EvMgr {
    virtual void f0();
    virtual void f1(s16 v);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
};

extern "C" Obj* fn_27_5041C(Obj* p, s32 flags) {
    if (p != nullptr) {
        s16 id = p->m4;
        p->vtbl = lbl_27_data_5288;
        if (id != -1) {
            EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), id);
            mgr->f1(p->m6);
        }
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
