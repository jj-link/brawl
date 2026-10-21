#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_84158(void*, int);
extern char lbl_27_data_16BE0[];
}

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
};

struct Mgr {
    virtual void f0();
    virtual void f1(s16);
};

extern "C" void* fn_27_AF50C(void* p, s32 flags) {
    if (p != 0) {
        if ((char*)p + 0xC != 0 && (char*)p + 0x1C != 0) {
            __destroy_arr((char*)p + 0x28, fn_27_84158, 0xC, 8);
        }
        if (p && p) {
            s16 id = ((Obj*)p)->m4;
            ((Obj*)p)->vtbl = lbl_27_data_16BE0;
            if (id != -1) {
                Mgr* mgr = (Mgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), id);
                mgr->f1(((Obj*)p)->m6);
            }
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
