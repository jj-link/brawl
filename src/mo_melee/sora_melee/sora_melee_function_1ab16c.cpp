#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84598(void*, s32);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern "C" char lbl_27_data_25FB0[];

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
};

struct EvMgr {
    virtual void v0();
    virtual void erase(s16 a);
};

extern "C" void* fn_27_1AB16C(Obj* self, s32 flag) {
    if (self) {
        if ((char*)self + 0x0C != 0 && (char*)self + 0x1C != 0) {
            __destroy_arr((char*)self + 0x28, (void (*)(void*, int))fn_27_84598, 0xC, 2);
        }
        if (self && self) {
            s16 id = self->m4;
            self->vtbl = lbl_27_data_25FB0;
            if (id != -1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->m4);
                mgr->erase(self->m6);
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
