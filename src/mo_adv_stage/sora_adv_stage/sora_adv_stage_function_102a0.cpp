#pragma force_active on
#include <types.h>
#include <nw4r/math/math_types.h>
#include <cm/cm_camera_controller.h>
#include <ec/ec_mgr.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

extern "C" float lbl_27_data_547E0;
extern "C" const float lbl_40_rodata_120[];

extern "C" {
void fn_800606C4(void* mgr, u32 flag);
void* fn_8009CD44(void* camera);
s32 fn_80019C10(void* manager, void* position);
u32 fn_8005F7CC(void* mgr, u32 effectID, const void* source, void* position);
}

static inline nw4r::math::VEC3 ScaleVector(
    const nw4r::math::VEC3& input, float factor)
{
    nw4r::math::VEC3 output;
    LocalScale((const Vec*)&input, (Vec*)&output, factor);
    return output;
}

static inline nw4r::math::VEC3 DivideVector(
    const nw4r::math::VEC3& input, float divisor)
{
    const float* c = lbl_40_rodata_120;
    float reciprocal = c[28] / divisor;
    nw4r::math::VEC3 output;
    LocalScale((const Vec*)&input, (Vec*)&output, reciprocal);
    return output;
}

struct Q4 {
    float x, y, z, w;

    Q4(float a, float b, float c)
        : x(a), y(b), z(c), w(lbl_40_rodata_120[24]) {}
};

struct EffData {
    float x, y, z;
    nw4r::math::VEC3 rot;
    u8 type;
    u8 pad[7];
    EfID id;
    float frame;
};

struct Self {
    u8 pad[0xC];
    EffData* data;
    u8 active;
    float frame;
    u32 handle;
};

extern "C" void fn_40_102A0(Self* self)
{
    const float* c = lbl_40_rodata_120;

    if (self->active == 1) {
        const EffData* effect = self->data;

        if (self->frame >= effect->frame) {
            switch (effect->type) {
            case 0:
                fn_800606C4(g_ecMgr, 1);
                self->handle = g_ecMgr->setEffect(self->data->id);
                fn_800606C4(g_ecMgr, 0);
                self->active = 0;
                break;

            case 1: {
                nw4r::math::VEC3 position =
                    DivideVector(ScaleVector(effect->rot, c[32]), c[33]);
                self->handle =
                    fn_8005F7CC(g_ecMgr, effect->id, effect, &position);
                self->active = 0;
                break;
            }

            case 2: {
                Q4 cam(effect->x, effect->y, effect->z);
                void* camera = CameraController::getInstance();
                void* manager = fn_8009CD44(camera);

                if (fn_80019C10(manager, &cam) == 0) {
                    if (self->handle != 0) {
                        g_ecMgr->endEffect(self->handle);
                        self->handle = 0;
                    }
                } else if (self->handle == 0) {
                    const EffData* cur = self->data;
                    nw4r::math::VEC3 position =
                        DivideVector(ScaleVector(cur->rot, c[32]), c[33]);
                    self->handle =
                        fn_8005F7CC(g_ecMgr, cur->id, cur, &position);
                }
                break;
            }
            }
        }

        float delta = lbl_27_data_547E0;
        self->frame += delta;
    }
}
