#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_26D04[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void __dt__6gfTaskFv(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_2ADF54(void*, int);
extern "C" void fn_27_2ADFB0(void*, int);
extern "C" void fn_27_2AE00C(void*, int);
extern "C" void fn_27_2AE068(void*, int);

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
    char pad0[0x40];
    void* v40;
    s16 m44;
    s16 m46;
    s16 m48;
};

extern "C" void* fn_27_2A1D30(void* arg, s32 flag) {
    if (arg) {
        Obj* p = (Obj*)arg;
        if ((char*)p + 0x1170) {
            __destroy_arr((char*)p + 0x1178, fn_27_2AE068, 0xC, 3);
        }
        if ((char*)p + 0x10C8) {
            __destroy_arr((char*)p + 0x10D0, fn_27_2AE00C, 0xC, 0xC);
        }
        if ((char*)p + 0xCE8) {
            __destroy_arr((char*)p + 0xCF0, fn_27_2ADFB0, 0xC, 0x40);
        }
        if ((char*)p + 0x9E0) {
            __destroy_arr((char*)p + 0x9E8, fn_27_2ADFB0, 0xC, 0x40);
        }
        if ((char*)p + 0x6D8) {
            __destroy_arr((char*)p + 0x6E0, fn_27_2ADFB0, 0xC, 0x40);
        }
        if ((char*)p + 0xC8) {
            __destroy_arr((char*)p + 0xD4, fn_27_2ADF54, 0xC, 0x80);
        }
        if ((char*)p + 0x40 && (char*)p + 0x40) {
            s16 id = p->m44;
            p->v40 = (void*)lbl_27_data_26D04;
            if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m44);
                mgr->v3(p->m46, p->m48);
            }
            p->m48 = -1;
            p->m44 = -1;
        }
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return arg;
}
