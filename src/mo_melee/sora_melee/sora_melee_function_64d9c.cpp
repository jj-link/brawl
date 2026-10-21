#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_75B8[];
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
    virtual s32 v6(s16 id);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16 a, s16 b);
};

struct Obj {
    void* vtbl;
    void* unk4;
    s16 m8;
    s16 mA;
    s16 mC;
};

extern "C" Obj* fn_27_64D9C(Obj* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 4 != 0 && (u32)p + 4 != 0) {
            s16 id = p->m8;
            p->unk4 = lbl_27_data_75B8;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m8);
                mgr->v3(p->mA, p->mC);
            }
            p->mC = -1;
            p->m8 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
