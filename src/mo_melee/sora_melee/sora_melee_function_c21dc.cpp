#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_C1A78(void*, int);

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
    u32 m0;
    u32 m4;
    u32 m8;
    void* vtbl;
    s16 m10;
    s16 m12;
    s16 m14;
};

extern "C" void* fn_27_C21DC(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        fn_27_C1A78((char*)p + 0x1C, -1);
        if ((char*)p + 0x0C && (char*)p + 0x0C) {
            s16 id = p->m10;
            p->vtbl = (void*)lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    p->m10);
                mgr->v3(p->m12, p->m14);
            }
            p->m14 = -1;
            p->m10 = -1;
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
