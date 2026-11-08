#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

extern char lbl_27_data_1180[];

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    static void __vt(int, int);
};

struct EvSys {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual u32 s8(s32 id);
};

struct EvMgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m5(s16 a, s16 b);
};

struct Ev {
    char pad0[4];
    void* vt4;
    s16 id8;
    s16 argA;
    s16 argC;
    char padE[2];
    void* vt10;
    s16 id14;
    s16 arg16;
    s16 arg18;
};

extern "C" Ev* fn_27_3544C(Ev* p, s32 flag) {
    if (p != nullptr) {
        if ((char*)p + 0x10 != nullptr && (char*)p + 0x10 != nullptr) {
            s16 id = p->id14;
            p->vt10 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->id14);
                mgr->m5(p->arg16, p->arg18);
            }
            p->arg18 = -1;
            p->id14 = -1;
        }
        if ((char*)p + 4 != nullptr && (char*)p + 4 != nullptr) {
            s16 id = p->id8;
            p->vt4 = lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->id8);
                mgr->m5(p->argA, p->argC);
            }
            p->argC = -1;
            p->id8 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
