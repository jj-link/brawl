#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

extern "C" {
void fn_800C1D2C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
extern void* lbl_805A0348;
}

struct State {
    unsigned int unk0;
    nw4r::g3d::G3dObj* obj4;
    nw4r::g3d::G3dObj* obj8;
    char data[0x3C8];
};

extern "C" void fn_8010D00C() {
    State* self = (State*)lbl_805A0348;
    if (self) {
        lbl_805A0348 = 0;
        __destroy_arr((char*)self + 0x154, fn_800C1D2C, 4, 0xA0);
        __destroy_arr((char*)self + 0xB4, fn_800C1D2C, 4, 0x28);
        __destroy_arr((char*)self + 0xAC, fn_800C1D2C, 4, 2);
        __destroy_arr((char*)self + 0x0C, fn_800C1D2C, 4, 0x28);
        if (&self->obj8) {
            if (self->obj8)
                self->obj8->Destroy();
            self->obj8 = 0;
        }
        if (&self->obj4) {
            if (self->obj4)
                self->obj4->Destroy();
            self->obj4 = 0;
        }
        __dl__FPv(self);
    }
    lbl_805A0348 = 0;
}
