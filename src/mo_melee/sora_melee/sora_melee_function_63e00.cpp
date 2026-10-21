#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_7310[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct EventSystem {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual u32 f6(s16);
};

struct EventManager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16, s16);
};

struct Obj {
    void* vptr;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" Obj* fn_27_63E00(Obj* p, s32 flag) {
    if (p != 0) {
        if (p != 0) {
            s16 id = p->m4;
            p->vptr = lbl_27_data_7310;

            if (((EventSystem*)getInstance__13soEventSystemFv())->f6(id) == 1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), p->m4))->f3(p->m6, p->m8);
            }

            p->m8 = -1;
            p->m4 = -1;
        }

        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
