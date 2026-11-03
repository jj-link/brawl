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
    char pad0[8];
    void* vt8;
    s16 h0C;
    s16 h0E;
    s16 h10;
    char pad12[2];
    void* vt14;
    s16 h18;
    s16 h1A;
    s16 h1C;
};

extern "C" Ev* fn_27_A995C(Ev* p, s32 flag) {
    if (p != nullptr) {
        if ((char*)p + 0x14 != nullptr && (char*)p + 0x14 != nullptr) {
            s16 id = p->h18;
            p->vt14 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->h18);
                mgr->m5(p->h1A, p->h1C);
            }
            p->h1C = -1;
            p->h18 = -1;
        }
        if ((char*)p + 8 != nullptr && (char*)p + 8 != nullptr) {
            s16 id = p->h0C;
            p->vt8 = lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->h0C);
                mgr->m5(p->h0E, p->h10);
            }
            p->h10 = -1;
            p->h0C = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
