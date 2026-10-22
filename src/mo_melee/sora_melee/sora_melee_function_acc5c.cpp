#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1180[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_27_ACEE4(void*, int);

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
    void* v4;
    s16 m8;
    s16 mA;
    s16 mC;
    s16 pad;
    void* v10;
    s16 m14;
    s16 m16;
    s16 m18;
};

extern "C" void* fn_27_ACC5C(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        if ((char*)p + 0x34) {
            __destroy_arr((char*)p + 0x40, (void (*)(void*, int))fn_27_ACEE4, 0xc, 1);
        }
        if ((char*)p + 0x10 && (char*)p + 0x10) {
            s16 id = p->m14;
            p->v10 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m14);
                mgr->v3(p->m16, p->m18);
            }
            p->m18 = -1;
            p->m14 = -1;
        }
        if ((char*)p + 4 && (char*)p + 4) {
            s16 id = p->m8;
            p->v4 = (void*)lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m8);
                mgr->v3(p->mA, p->mC);
            }
            p->mC = -1;
            p->m8 = -1;
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
