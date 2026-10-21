#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_260F0[];
}

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int  v8(s16);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16, s16);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" void* fn_27_CDA70(void* p, s32 flag) {
    Obj* o = (Obj*)p;
    if (p != nullptr) {
        if (p != nullptr) {
            s16 id = o->m4;
            o->vtbl = (void*)lbl_27_data_260F0;
            if (static_cast<unsigned>(((EvSys*)getInstance__13soEventSystemFv())->v8(id)) == 1u) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), o->m4);
                mgr->v3(o->m6, o->m8);
            }
            o->m8 = -1;
            o->m4 = -1;
        }
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
