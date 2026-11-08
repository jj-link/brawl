#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" char lbl_27_data_2A918[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_5A09C(void*, int);
extern "C" void* __dt__22soControllerModuleImplFv(void*, short);

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
    char pad[0x14];
    void* vt14;
    s16 h18, h1a, h1c;
    char pad1e[2];
    void* vt20;
    s16 h24, h26, h28;
};

extern "C" void* fn_27_150488(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        fn_27_5A09C((char*)p + 0xBC, -1);
        fn_27_5A09C((char*)p + 0x30, -1);
        if ((char*)p + 0x20 && (char*)p + 0x20) {
            s16 id = p->h24;
            p->vt20 = (void*)lbl_27_data_2A918;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    p->h24);
                mgr->v3(p->h26, p->h28);
            }
            p->h28 = -1;
            p->h24 = -1;
        }
        if ((char*)p + 0x14 && (char*)p + 0x14) {
            s16 id = p->h18;
            p->vt14 = (void*)lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(),
                    p->h18);
                mgr->v3(p->h1a, p->h1c);
            }
            p->h1c = -1;
            p->h18 = -1;
        }
        __dt__22soControllerModuleImplFv(arg, 0);
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
