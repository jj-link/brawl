#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

struct MenuModel {
    char pad[0x3c];
    Vec3f translation;

    Vec3f position() const {
        Vec3f pos;
        pos.m_x = translation.m_x;
        pos.m_y = translation.m_y;
        pos.m_z = translation.m_z;
        return pos;
    }
};

struct Hand {
    char pad[0x90];
    Vec2f translation;

    Vec2f position() const {
        return Vec2f(translation.m_x, translation.m_y);
    }
};

struct Cursor {
    char pad0[4];
    MenuModel* model;
    char pad8[8];
    Hand* hand;
    char pad14[4];
    s32 state;
};

inline Vec2f planePosition(const Vec3f& v) {
    return Vec2f(v.m_x, v.m_y);
}

extern "C" {
extern const f32 lbl_10_rodata_870[];
void fn_800B6838(MenuModel*, const Vec3f*);
}

static inline void setPosition(Cursor* self, const Vec2f& position, const f32* k) {
    Vec3f result;
    f32 y = position.m_y;
    result.m_x = position.m_x;
    result.m_y = y;
    result.m_z = k[0];
    fn_800B6838(self->model, &result);
}

extern "C" void fn_10_1C154(Cursor* self) {
    const f32* k = lbl_10_rodata_870;
    Vec2f target;
    Vec2f::copy(target, self->hand->position());
    Vec2f delta = target - planePosition(self->model->position());
    f32 squared = delta.m_x * delta.m_x + delta.m_y * delta.m_y;
    f32 length;
    if ((f32)(double)nw4r::math::FAbs(squared) <= k[6]) {
        length = k[5];
    } else {
        length = squared * rsqrtf(squared);
    }
    int arrived;
    if (length > k[7]) {
        f32 scale = k[7] / length;
        delta.m_x *= scale;
        delta.m_y *= scale;
        arrived = 0;
    } else {
        arrived = 1;
    }
    Vec2f next = planePosition(self->model->position());
    next.m_x += delta.m_x;
    next.m_y += delta.m_y;
    setPosition(self, next, k);
    if (arrived) {
        self->state = 0;
    }
}
