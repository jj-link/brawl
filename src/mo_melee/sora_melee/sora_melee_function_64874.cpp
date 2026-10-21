#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_7310[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct fn27Obj {
    void* vptr;
    s16 m_4;
    s16 m_6;
    s16 m_8;
};

struct fn27EventSystem {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual bool fn6(s16);
};

struct fn27Mgr {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3(s16, s16);
};

extern "C" fn27Obj* fn_27_64874(fn27Obj* p, s32 flag) {
    if (p != 0) {
        s16 id = p->m_4;
        p->vptr = lbl_27_data_7310;

        if (((fn27EventSystem*)getInstance__13soEventSystemFv())->fn6(id) == 1) {
            ((fn27Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), p->m_4))->fn3(p->m_6, p->m_8);
        }

        p->m_8 = -1;
        p->m_4 = -1;

        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
