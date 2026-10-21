#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_16BE0[];
}

struct fn27Obj {
    void* vptr;
    s16 m_4;
    s16 m_6;
};

struct fn27Mgr {
    virtual ~fn27Mgr() { }
    virtual void b(s16 v);
};

extern "C" void* fn_27_AF5D0(void* p, s32 flag) {
    if (p != nullptr) {
        s16 id = ((fn27Obj*)p)->m_4;
        *(void**)p = lbl_27_data_16BE0;
        if (id != -1) {
            fn27Mgr* mgr = (fn27Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), id);
            mgr->b(((fn27Obj*)p)->m_6);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
