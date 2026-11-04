#include <mt/mt_vector.h>
#include <mt/mt_prng.h>

#pragma force_active on
#pragma fp_contract off
#pragma opt_propagation off

extern const float lbl_15_rodata_0[];
extern "C" void fn_800B6838(void*, const Vec3f*);
extern "C" void fn_800B6F6C(void*, const Vec3f*);

struct WatchState {
    int index;
    float speed;
    float time;
    float x;
    float y;
    float z;
};

extern "C" void fn_15_10B0(void* self, WatchState* state) {
    const float* c = lbl_15_rodata_0;
    void* object = ((void**)((char*)self + 0x4C))[state->index];
    Vec3f pos;
    pos.m_x = c[0xD4 / 4] + c[0xD8 / 4] * randf();
    pos.m_y = c[0xDC / 4];
    pos.m_z = c[0xE0 / 4];
    fn_800B6838(object, &pos);
    state->time = c[0];
    state->speed = c[0xE4 / 4] + randf();
    Vec3f rot;
    rot.m_x = c[0xE8 / 4] * (c[0xEC / 4] * randf()) - c[0xEC / 4];
    rot.m_y = c[0xE8 / 4] * (c[0xEC / 4] * randf()) - c[0xEC / 4];
    rot.m_z = c[0xE8 / 4] * (c[0xEC / 4] * randf()) - c[0xEC / 4];
    fn_800B6F6C(object, &rot);
    state->x = c[0xF0 / 4] + c[0xF4 / 4] * randf();
    state->y = c[0xF0 / 4] + c[0xF4 / 4] * randf();
    state->z = c[0xF0 / 4] + c[0xF4 / 4] * randf();
}
