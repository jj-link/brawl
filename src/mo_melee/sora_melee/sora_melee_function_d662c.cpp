#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_84398(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_26050[];
}

struct EvMgr {
    virtual void v0();
    virtual void v1(s16 a);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
};

extern "C" void* fn_27_D662C(Obj* p, s32 flag) {
    if (p) {
        if (((char*)p + 0xc) != 0 && ((char*)p + 0x1c) != 0)
            __destroy_arr((char*)p + 0x28, fn_27_84398, 0xc, 0x17);
        if (p) {
            if (p) {
                s16 id = p->m4;
                p->vtbl = (void*)lbl_27_data_26050;
                if (id != -1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), p->m4);
                    mgr->v1(p->m6);
                }
            }
        }
        if (flag > 0) __dl__FPv((void*)p);
    }
    return p;
}
