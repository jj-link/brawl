#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

extern char lbl_27_data_1180[];
extern char lbl_27_data_5B3C[];

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
    char pad0[0xc];
    void* vtC;
    s16 h10;
    s16 h12;
    s16 h14;
    char pad16[2];
    void* vt18;
    s16 h1C;
    s16 h1E;
    s16 h20;
    char pad22[0xe];
    void* vt30;
    s16 h34;
    s16 h36;
    s16 h38;
};

extern "C" Ev* fn_27_5CC1C(Ev* p, s32 flag) {
    if (p != nullptr) {
        if ((char*)p + 0x30 != nullptr && (char*)p + 0x30 != nullptr) {
            s16 id = p->h34;
            p->vt30 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->h34);
                mgr->m5(p->h36, p->h38);
            }
            p->h38 = -1;
            p->h34 = -1;
        }
        if ((char*)p + 0x18 != nullptr && (char*)p + 0x18 != nullptr) {
            s16 id = p->h1C;
            p->vt18 = lbl_27_data_1180;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->h1C);
                mgr->m5(p->h1E, p->h20);
            }
            p->h20 = -1;
            p->h1C = -1;
        }
        if ((char*)p + 0xc != nullptr && (char*)p + 0xc != nullptr) {
            s16 id = p->h10;
            p->vtC = lbl_27_data_5B3C;
            if (((EvSys*)getInstance__13soEventSystemFv())->s8(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->h10);
                mgr->m5(p->h12, p->h14);
            }
            p->h14 = -1;
            p->h10 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
