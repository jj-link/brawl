#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" char lbl_27_data_1F78[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_C0F70(char* p, s32 n);

class soAnimCmdEventObserver;
template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

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
    void* v8;
    s16 mC;
    s16 mE;
    s16 m10;
    s16 m12;
    void* v14;
    s16 m18;
    s16 m1A;
    s16 m1C;
    s16 pad1E;
    void* v20;
    s16 m24;
    s16 m26;
    s16 m28;
};

extern "C" void* fn_27_BED74(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        fn_27_C0F70((char*)p + 0xB8, -1);
        fn_27_C0F70((char*)p + 0x30, -1);
        if ((char*)p + 0x20 && (char*)p + 0x20) {
            s16 id = p->m24;
            p->v20 = (void*)lbl_27_data_1F78;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m24);
                mgr->v3(p->m26, p->m28);
            }
            p->m28 = -1;
            p->m24 = -1;
        }
        if ((char*)p + 0x14 && (char*)p + 0x14) {
            s16 id = p->m18;
            p->v14 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m18);
                mgr->v3(p->m1A, p->m1C);
            }
            p->m1C = -1;
            p->m18 = -1;
        }
        if ((char*)p + 0x8 && (char*)p + 0x8) {
            s16 id = p->mC;
            p->v8 = (void*)lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->mC);
                mgr->v3(p->mE, p->m10);
            }
            p->m10 = -1;
            p->mC = -1;
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
