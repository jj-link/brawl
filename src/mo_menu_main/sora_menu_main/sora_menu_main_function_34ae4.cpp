#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on
extern "C" void fn_1_7EB8(void*, void*);
struct Model { char pad[0x10]; void* field10; };
struct Inner { void* field0; char pad04[0x70]; Model* model; char pad78[0x38]; int state; char padb4[0x10]; int flag; char padc8[0xf0]; int field1b8; };
struct Self { char pad[0x40]; Inner* obj; };
struct FuncTable { char pad[0x20]; void (*func)(Self*); };
extern "C" const FuncTable lbl_2_rodata_1408;
static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}
static inline bool pressed(Self* self) {
    gfPadStatus status = getSysPad();
    if (status.m_buttonsPressedThisFrame.bits != 0 || self->obj->flag != 0) return true;
    return false;
}
extern "C" void fn_2_34AE4(Self* self) {
    if (pressed(self)) {
        fn_1_7EB8(self->obj->field0, self->obj->model->field10);
        self->obj->field1b8 = 0;
        if (lbl_2_rodata_1408.func) lbl_2_rodata_1408.func(self);
        self->obj->state = 4;
    }
}