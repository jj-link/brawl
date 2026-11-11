#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {
extern float lbl_29_rodata_0[];
void fn_800B6838(void*, const Vec3f*);
float rsqrtf__Ff(float);
}

struct Menu {
    char pad[0x150];
    Vec2f position(int n) {
        char* p = (char*)this + n * 0x14;
        return Vec2f(*(float*)(p + 0x270), *(float*)(p + 0x274));
    }
    int index(int n) const {
        return *(int*)((char*)this + n * 0xd8 + 0x190);
    }
};

static inline float vectorLength(Vec2f& delta) {
    float distance = delta.m_x * delta.m_x + delta.m_y * delta.m_y;
    if ((float)(double)nw4r::ut::Abs(distance) <= lbl_29_rodata_0[32])
        return lbl_29_rodata_0[28];
    return distance * rsqrtf__Ff(distance);
}

extern "C" void fn_29_D84(Menu* self, int n) {
    const f32* k = lbl_29_rodata_0;
    u8* obj = *(u8**)((char*)self + (n + 2) * 4 + 0x4c);
    Vec3f pos;
    pos.m_x = *(f32*)(obj + 0x3c);
    pos.m_y = *(f32*)(obj + 0x40);
    pos.m_z = *(f32*)(obj + 0x44);
    Vec2f delta;
    Vec2f origin(pos.m_x, pos.m_y);
    Vec2f target = self->position(self->index(n));
    delta = target - origin;
    f32 distance = vectorLength(delta);
    if (distance < k[33]) {
        pos.m_x = target.m_x;
        pos.m_y = target.m_y;
        fn_800B6838(obj, &pos);
        return;
    }
    delta.m_x *= k[34];
    delta.m_y *= k[34];
    origin.m_x += delta.m_x;
    origin.m_y += delta.m_y;
    pos.m_x = origin.m_x;
    pos.m_y = origin.m_y;
    fn_800B6838(obj, &pos);
}
