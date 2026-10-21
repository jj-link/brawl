#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_27_84318(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern "C" char lbl_27_data_25F10[];

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

struct Obj {
    void* vtable;
    s16 id;
    s16 index;
};

extern "C" Obj* fn_27_D815C(Obj* self, s32 del) {
    if (self != 0) {
        if ((char*)self + 0xC != 0 && (char*)self + 0x1C != 0) {
            __destroy_arr((char*)self + 0x28,
                          (void (*)(void*, int))fn_27_84318, 0xCul, 1ul);
        }
        if (self != 0 && self != 0) {
            s16 id = self->id;
            self->vtable = lbl_27_data_25F10;
            if (id != -1) {
                ((EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), self->id))->fn1(self->index);
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
