#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <types.h>
#pragma force_active on
struct FloatSource {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual float getValue();
};
struct LevelB { char pad[0xC]; FloatSource* source; };
struct LevelA { char pad[0x14]; LevelB* next; };
struct State { char pad[0x10]; LevelA* first; char pad14[0x9C]; int state; char padB4[0x10]; int fieldC4; };
struct Self { char pad[0x40]; State* state; };
extern "C" { extern float lbl_2_rodata_1578; extern void* lbl_2_rodata_1408; }
static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}
static inline bool pressed(Self* self) {
    gfPadStatus status = getSysPad();
    if (status.m_buttonsPressedThisFrame.bits != 0 || self->state->fieldC4 != 0) return true;
    return false;
}
extern "C" void fn_2_326D0(Self* self) {
    float value = self->state->first->next->source->getValue();
    if (value >= lbl_2_rodata_1578 || pressed(self)) {
        void* func = *(void**)((char*)&lbl_2_rodata_1408 + 0x10);
        if (func) ((void (*)(Self*))func)(self);
        self->state->state = 2;
    }
}