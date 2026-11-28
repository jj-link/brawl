#include <types.h>
#include <nw4r/math/math_types.h>
#include <cm/cm_camera_controller.h>
#include <cm/cm_controller_ai.h>
#include <gf/gf_camera.h>
#pragma force_active on

// CodeWarrior check: 95.6% match, with 28 differing lines.
extern "C" {
f64 fn_80400AB8(f64);
void fn_8009CE3C(CameraController*, void*);
void fn_80018778(gfCamera*);
void fn_800A0804(cmAIController*, f32);
}

extern const f32 lbl_805A215C;
extern const f32 lbl_805A2160;
extern const f32 lbl_805A2164;
extern const f32 lbl_805A2154;
extern const f32 lbl_805A2158;

struct Target {
    char pad[0x10];
    nw4r::math::VEC3 pos;
    char pad1[0x10];
    f32 left, right, top, bottom;
};

struct State {
    gfCamera* camera;
    void* unused;
    Target* object;
    u16 frame, duration;
    u8 pad10, flags;
    char pad12[2];
    f32 distance;
    nw4r::math::VEC3 startTarget, endTarget, startEye, endEye, direction;
    f32 time;
};

extern "C" void fn_800AA570(State* self, f32 delta) {
    nw4r::math::VEC3 target, eye, offset, difference, scaledOffset, scaled, sum;
    gfCamera* camera = self->camera;

    if (self->object != NULL) {
        if ((self->flags >> 6) & 1) {
            f32 t = self->duration ? self->time / (f32)self->duration : lbl_805A215C;
            register f32 x;
            f32 angle;
            f32 height;
            f32 width;
            f32 half;
            f32 horizontal;
            f32 fov;
            f32 vertical;
            horizontal = self->object->right - self->object->left;
            half = lbl_805A2158;
            fov = camera->unkD0;
            vertical = self->object->top - self->object->bottom;
            angle = half * fov;
            width = half * horizontal;
            height = half * vertical;
            f32 tangent = (f32)fn_80400AB8(angle);
            f32 aspect = *reinterpret_cast<const f32*>(camera->_spacer2);
            x = width / (tangent * aspect);

            register f64 largest;
            register f32 y, lower;
            y = height / (f32)fn_80400AB8(angle);
            lower = lbl_805A2160;
            asm { ps_sub largest, x, y }
            asm { ps_sel largest, largest, x, y }
            largest = (f32)largest;
            asm { ps_sub y, largest, lower }
            asm { ps_sel y, y, largest, lower }
            self->distance = y;

            register State* state = self;
            register nw4r::math::VEC3* ps = &scaled;
            register f32 scaledZ, directionXY, directionZ;
            asm { psq_l directionXY, State.direction(state), 0, 0 }
            asm { psq_l directionZ, State.direction + 8(state), 1, 0 }
            y = self->distance;
            asm { ps_muls0 directionXY, directionXY, y }
            asm { ps_muls0 scaledZ, directionZ, y }
            asm { psq_st scaledZ, 8(ps), 1, 0 }
            self->endEye = self->object->pos;

            register nw4r::math::VEC3* result = &sum;
            register f32 eyeZ;
            asm { psq_l y, State.endEye(state), 0, 0 }
            asm { ps_add y, y, directionXY }
            asm { psq_l eyeZ, State.endEye + 8(state), 1, 0 }
            asm { psq_st directionXY, 0(ps), 0, 0 }
            asm { ps_add eyeZ, eyeZ, scaledZ }
            asm { psq_st y, 0(result), 0, 0 }
            asm { psq_st eyeZ, 8(result), 1, 0 }
            self->endTarget = sum;

            s32 valid = 1;
            CameraController* controller = CameraController::getInstance();
            if (!((((u8*)controller)[0x44] >> 2) & 1)) {
                CameraController* c = CameraController::getInstance();
                f32* bounds = (f32*)((char*)c + 0x148);
                f32 extra = *(f32*)((char*)c + 0x18c);
                if (self->endEye.x < bounds[0] ||
                    self->endEye.x > bounds[1] ||
                    self->endEye.y > bounds[2] ||
                    self->endEye.y < bounds[3] + extra) {
                    valid = 0;
                } else {
                    valid = 1;
                }
            }

            if (!valid) {
                fn_8009CE3C(controller, self->object);
                self->flags |= 0x80;
                self->frame = self->duration;
                self->time = (f32)self->duration;
            } else {
                register State* state = self;
                register nw4r::math::VEC3* pt = &target;
                register nw4r::math::VEC3* pe = &eye;
                register nw4r::math::VEC3* pd = &difference;
                register f32 tt = t;
                register f32 weightedTargetXY;
                register f32 targetZ;
                register f32 scratch;
                register f32 targetXY;
                register f32 remaining;
                register f32 eyeXY;
                register f32 endEyeZ;
                register f32 endEyeXY;
                register f32 startEyeZ;
                remaining = lbl_805A215C - t;

                asm { psq_l scratch, State.startTarget(state), 0, 0 }
                asm { psq_l eyeXY, State.startEye(state), 0, 0 }
                asm { psq_l targetZ, State.startTarget + 8(state), 1, 0 }
                asm { psq_l startEyeZ, State.startEye + 8(state), 1, 0 }
                asm { ps_muls0 weightedTargetXY, scratch, remaining }
                asm { psq_l targetXY, State.endTarget(state), 0, 0 }
                asm { ps_muls0 eyeXY, eyeXY, remaining }
                asm { psq_l endEyeXY, State.endEye(state), 0, 0 }
                asm { ps_muls0 targetZ, targetZ, remaining }
                asm { psq_l scratch, State.endTarget + 8(state), 1, 0 }
                asm { ps_madds0 targetXY, targetXY, tt, weightedTargetXY }
                asm { psq_l endEyeZ, State.endEye + 8(state), 1, 0 }
                asm { ps_madds0 eyeXY, endEyeXY, tt, eyeXY }
                weightedTargetXY = lbl_805A2164;
                asm { ps_madds0 targetZ, scratch, tt, targetZ }
                asm { ps_muls0 remaining, startEyeZ, remaining }
                asm { ps_sub scratch, targetXY, eyeXY }
                asm { psq_st targetXY, 0(pt), 0, 0 }
                asm { ps_madds0 remaining, endEyeZ, tt, remaining }
                asm { psq_st targetZ, 8(pt), 1, 0 }
                asm { psq_st scratch, 0(pd), 0, 0 }
                asm { ps_sub targetXY, targetZ, remaining }
                asm { psq_st targetXY, 8(pd), 1, 0 }
                asm { psq_st eyeXY, 0(pe), 0, 0 }
                asm { psq_st remaining, 8(pe), 1, 0 }

                scratch = difference.x;
                targetZ = difference.y;
                targetXY = difference.z;
                scratch *= scratch;
                targetZ *= targetZ;
                targetXY *= targetXY;
                targetZ = scratch + targetZ;
                targetZ = targetXY + targetZ;
                if (targetZ < weightedTargetXY) {
                    target.z += lbl_805A2160;
                }

                camera->m_targetPos = reinterpret_cast<const Vec3f&>(eye);
                camera->unkFA.m_mask |= 2;
                camera->m_centerPos = reinterpret_cast<const Vec3f&>(target);

                offset.x = lbl_805A2154;
                offset.y = lbl_805A2154;
                offset.z = lbl_805A2154;
                if (t < lbl_805A215C) {
                    register const Vec3f* in = &camera->m_0x9C;
                    register nw4r::math::VEC3* out = &scaledOffset;
                    register f32 weight, offsetXY, offsetZ;
                    weight = lbl_805A215C - t;
                    asm { psq_l offsetXY, Vec3f.m_x(in), 0, 0 }
                    asm { psq_l offsetZ, Vec3f.m_z(in), 1, 0 }
                    asm { ps_muls0 offsetXY, offsetXY, weight }
                    asm { ps_muls0 weight, offsetZ, weight }
                    asm { psq_st offsetXY, 0(out), 0, 0 }
                    asm { psq_st weight, 8(out), 1, 0 }
                    offset = scaledOffset;
                }

                camera->m_0x9C = reinterpret_cast<const Vec3f&>(offset);
                camera->m_transformFlag.m_mask = 0x43;
                fn_80018778(camera);
            }
        }

        self->time += delta;
        self->frame = (u16)(s32)self->time;
        if (self->frame >= self->duration) {
            self->flags |= 0x80;
            self->frame = self->duration;
            self->time = (f32)self->duration;
        }
    }

    fn_800A0804(g_cmAIController, delta);
}
