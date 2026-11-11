#include <types.h>
#include <gf/gf_camera.h>
#include <gf/gf_application.h>
#include <gm/gm_global.h>
#pragma force_active on
class gfCameraController_base { public: char pad[0x4]; };
class gfCameraController : public gfCameraController_base { public: virtual void slot0(float f); };
struct CameraSelf {
    char pad0[0x40]; s32 mode40; u8 flags44; char pad1[0x3];
    gfCameraController* ctrl48; char pad2[0xC]; void* cam58;
    char pad3[0x20]; void* ptr7C; char pad4[0x104]; f32 f184; s32 cnt188;
};
extern "C" {
float fn_8004E94C(void*);
void fn_8009D744(void*, float);
void fn_8009EC5C(float);
void* fn_8009E3F4(void*, float);
void fn_8009EA18(void*, void*);
}
extern "C" void fn_8009CA88(CameraSelf* self) {
    s32 r30 = (*(u32*)((char*)g_gfApplication + 0xEC) >> 27) != 0;
    if ((self->flags44 >> 7) & 1) {
        f32 f31 = fn_8004E94C(g_GameGlobal);
        if (r30 == 0) fn_8009EC5C(f31);
        if (self->ptr7C != 0) fn_8009D744(self->ptr7C, f31);
        if (self->mode40 == 7) self->ctrl48->slot0(f31);
        else if (r30 == 0) self->ctrl48->slot0(f31);
        else if (r30 != 0 && (*(u8*)((char*)g_gfApplication + 0xED) & 1))
            self->ctrl48->slot0(f31);
        s32 var;
        if (!((self->flags44 >> 3) & 1)) var = 0;
        else {
            switch (self->mode40) {
            case 12:
            case 2:
                if (!self->cam58) var = 0;
                else var = (((u8*)self->cam58)[0x94] >> 4) & 1;
                break;
            default: var = 0; break;
            }
        }
        if (var != 0) {
            fn_8009E3F4((char*)self + 0x194, f31);
            if (self->cnt188 <= 0)
                fn_8009EA18((void*)((u32)self + 0x194), gfCameraManager::getManager());
        }
        self->f184 = self->f184 + f31;
    }
}