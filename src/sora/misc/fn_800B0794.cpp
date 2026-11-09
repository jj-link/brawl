#pragma force_active on
#include <gf/gf_camera.h>

extern "C" {
void fn_80018778(void*);
void fn_80018EC4(void*, void*);
void fn_800B04AC(void*);
void fn_800B05A0(void*);
s32 fn_801AC554(s32, s32);
void* fn_801AC5EC(s32, s32);
void fn_801ACB68(s32);
void fn_801ACBB4(s32);
void fn_801ACBEC(s32);
void fn_801ACC64(s32);
void fn_801ACD50(s32);
}

struct Obj {
    char pad[0x48];
    s32 unk48;
};

extern "C" void fn_800B0794(Obj* self) {
    s32 sp8;
    void* mgr;
    if (self->unk48 != 0) {
        fn_801AC5EC(self->unk48, 0);
        fn_801ACB68(self->unk48);
        fn_800B04AC(self);
        fn_801ACBB4(self->unk48);
        fn_800B05A0(self);
        if (self->unk48 != 0) {
            fn_801AC5EC(self->unk48, 0);
            mgr = gfCameraManager::getManager();
            sp8 = fn_801AC554(self->unk48, 0);
            fn_80018EC4(mgr, &sp8);
            fn_80018778(mgr);
        }
        fn_801ACBEC(self->unk48);
        fn_801ACC64(self->unk48);
        fn_801ACD50(self->unk48);
    }
}
