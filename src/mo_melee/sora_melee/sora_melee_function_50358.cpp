#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_505E0(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_5288[];
}

struct EvMgr {
    virtual void f0();
    virtual void f1(s16 v);
};

extern "C" void* fn_27_50358(char* p, int flags) {
    if (p) {
        if (p + 0x0C) {
            if (p + 0x1C) {
                __destroy_arr(p + 0x28, fn_27_505E0, 0xC, 0xFF);
            }
        }
        if (p) {
            if (p) {
                s16 id = *(s16*)(p + 4);
                *(void**)p = lbl_27_data_5288;
                if (id != -1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), id);
                    mgr->f1(*(s16*)(p + 6));
                }
            }
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
