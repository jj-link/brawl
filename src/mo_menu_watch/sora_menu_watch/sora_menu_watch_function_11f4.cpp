#include <mt/mt_vector.h>

#pragma force_active on
#pragma fp_contract off
#pragma opt_propagation off

extern const float lbl_15_rodata_0[];
extern "C" void fn_800B6838(void*, const Vec3f*);
extern "C" void fn_800B6F6C(void*, const Vec3f*);
extern "C" void fn_80075F1C(void*, unsigned int, int);
extern void* g_sndSystem;

struct WatchState {
    int index;
    float speed;
    float time;
    float x;
    float y;
    float z;
};

extern "C" int fn_15_11F4(void* self, WatchState* state) {
    const float* c = lbl_15_rodata_0;
    void* object = ((void**)((char*)self + 0x4C))[state->index];
    state->time -= c[0xF8 / 4];
    Vec3f pos;
    pos = *(Vec3f*)((char*)object + 0x3C);
    pos.m_x += state->speed;
    pos.m_y += state->time;
    fn_800B6838(object, &pos);
    Vec3f rot;
    rot = *(Vec3f*)((char*)object + 0x48);
    rot.m_x += state->x;
    while (rot.m_x > c[0xEC / 4]) rot.m_x -= c[0xFC / 4];
    while (rot.m_x < c[0x100 / 4]) rot.m_x += c[0xFC / 4];
    rot.m_y += state->y;
    while (rot.m_y > c[0xEC / 4]) rot.m_y -= c[0xFC / 4];
    while (rot.m_y < c[0x100 / 4]) rot.m_y += c[0xFC / 4];
    rot.m_z += state->z;
    while (rot.m_z > c[0xEC / 4]) rot.m_z -= c[0xFC / 4];
    while (rot.m_z < c[0x100 / 4]) rot.m_z += c[0xFC / 4];
    fn_800B6F6C(object, &rot);
    if (*(int*)((char*)self + 0xD44) <= 0 && pos.m_y < c[0x104 / 4]) {
        unsigned int sound = *(unsigned int*)((char*)self + 0xD6C);
        if (sound != -1U) {
            fn_80075F1C(g_sndSystem, sound, 0);
            *(unsigned int*)((char*)self + 0xD6C) = -1U;
        }
    }
    return !(pos.m_y < c[0x108 / 4]);
}
