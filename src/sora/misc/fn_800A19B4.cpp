#include <types.h>
#include <cm/cm_camera_controller.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct CameraState {
    char pad[0x94];
    unsigned char flags;
    char pad95[0xE0 - 0x95];
    float lowRate, highRate, lowSize, highSize;
};
struct Bounds {
    Vec2f minimum;
    Vec2f maximum;
    int valid;
};
extern "C" {
extern const float lbl_805A1E84;
extern const float lbl_805A1EF4;
extern const float lbl_805A1EF8;
}

inline float clampAmount(float lower, float upper, float diff, float amount) {
    amount = nw4r::math::FSelect(diff, amount, lower);
    diff = amount - upper;
    return nw4r::math::FSelect(diff, upper, amount);
}

extern "C" void fn_800A19B4(CameraState* self, Vec3f* position, const Bounds* bounds, float time) {
    register f32 size;
    if (bounds->valid) {
        Vec2f extent = bounds->maximum - bounds->minimum;
        register f32 ex = extent.m_x;
        register f32 ey = extent.m_y;
        asm { ps_sub size, ex, ey }
        asm { ps_sel size, size, ex, ey }
        if ((self->flags >> 6) & 1) {
            CameraController* camera = CameraController::getInstance();
            float* range = reinterpret_cast<float*>(camera->_328);
            register f32 wf = range[1] - range[0];
            register f32 dwh;
            register f32 hf = range[2] - range[3];
            register f32 smaller, res;
            asm { ps_sub dwh, wf, hf }
            asm { ps_sel smaller, dwh, hf, wf }
            asm { ps_sub res, size, smaller }
            asm { ps_sel res, res, smaller, size }
            size = res;
        }
    } else {
        size = lbl_805A1EF4;
    }
    Vec2f delta;
    delta.m_x = position[1].m_x - position[0].m_x;
    delta.m_y = position[1].m_y - position[0].m_y;
    float rate;
    if (size > self->highSize)
        rate = self->highRate;
    else if (size < self->lowSize)
        rate = self->lowRate;
    else
        rate = self->lowRate + (self->highRate - self->lowRate) * ((size - self->lowSize) / (self->highSize - self->lowSize));
    float amount = clampAmount(lbl_805A1EF8, lbl_805A1E84, rate * time - lbl_805A1EF8, rate * time);
    position->m_x += delta.m_x * amount;
    position->m_y += delta.m_y * amount;
}
