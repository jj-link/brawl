#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1F78[];
extern "C" char lbl_27_data_1180[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

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
    virtual u32 v6(s16 id);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16 a, s16 b);
};

struct Obj {
    u8 pad0[4];
    void* unk4;
    s16 m8;
    s16 mA;
    s16 mC;
    u8 padE[2];
    void* unk10;
    s16 m14;
    s16 m16;
    s16 m18;
    u8 pad1A[2];
    void* unk1C;
    s16 m20;
    s16 m22;
    s16 m24;
};

extern "C" Obj* fn_27_B64B8(Obj* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x1C != 0 && (u32)p + 0x1C != 0) {
            s16 id = p->m20;
            p->unk1C = lbl_27_data_1F78;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m20);
                mgr->v3(p->m22, p->m24);
            }
            p->m24 = -1;
            p->m20 = -1;
        }
        if ((u32)p + 0x10 != 0 && (u32)p + 0x10 != 0) {
            s16 id = p->m14;
            p->unk10 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m14);
                mgr->v3(p->m16, p->m18);
            }
            p->m18 = -1;
            p->m14 = -1;
        }
        if ((u32)p + 0x4 != 0 && (u32)p + 0x4 != 0) {
            s16 id = p->m8;
            p->unk4 = lbl_27_data_1180;
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
