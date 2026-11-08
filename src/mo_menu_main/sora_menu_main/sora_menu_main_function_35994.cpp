#pragma force_active on
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
extern "C" void fn_1_7EB8(void*, void*);
struct Self;
struct FuncTable { char pad[0x30]; void (*func)(Self*); };
extern "C" const FuncTable lbl_2_rodata_1408;
struct Obj { char pad00[0xB0]; int state; char padB4[0x10]; int fieldC4; char padC8[0xF8]; short timer; };
struct Self { char pad[0x40]; Obj* obj; };
static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}
static inline bool pressed(Self* self) {
    gfPadStatus status = getSysPad();
    if (status.m_buttonsPressedThisFrame.bits != 0 || self->obj->fieldC4 != 0) return true;
    return false;
}
extern "C" void fn_2_35994(Self* self) {
    if (!pressed(self)) {
        int timer = self->obj->timer - 1;
        self->obj->timer = timer;
        if ((short)timer > 0) return;
    }
    fn_1_7EB8(*(void**)self->obj, *(void**)(*(char**)((char*)self->obj + 0x74) + 0x10));
    self->obj->pad00[0]; 
    *(int*)((char*)self->obj + 0x1B8) = 0;
    if (lbl_2_rodata_1408.func)
        lbl_2_rodata_1408.func(self);
    self->obj->state = 6;
}
