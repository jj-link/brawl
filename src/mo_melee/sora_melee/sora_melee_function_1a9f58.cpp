#include <types.h>
#pragma force_active on

extern "C" void fn_27_84458(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" char lbl_27_data_26028[];

struct EvMgr {
    virtual void v0();
    virtual void v1(s16);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
};

extern "C" Obj* fn_27_1A9F58(Obj* self, s32 flag) {
    if (self) {
        if ((char*)self + 0xC != 0 && (char*)self + 0x1C != 0) {
            __destroy_arr((char*)self + 0x28, fn_27_84458, 0xC, 0x14);
        }
        if (self) {
            if (self) {
                s16 id = self->m4;
                self->vtbl = lbl_27_data_26028;
                if (id != -1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->m4);
                    mgr->v1(self->m6);
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
