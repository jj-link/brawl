#include <mt/mt_vector.h>

#pragma force_active on
#pragma fp_contract off
#pragma opt_propagation off

extern const float lbl_34_rodata_0[];
extern "C" void fn_800B6838(void*, const Vec3f*);
extern "C" void fn_800B6F6C(void*, const Vec3f*);
extern "C" void fn_80075F1C(void*, unsigned int, int);
extern void* g_sndSystem;

struct ResultState {
    int index;
    float speed;
    float time;
    float x;
    float y;
    float z;
};

extern "C" int fn_34_1454(void* self, ResultState* state) {
    const float* c = lbl_34_rodata_0;
    void* object = ((void**)((char*)self + 0x138))[state->index];

    state->time -= c[0xA8 / 4];

    Vec3f pos;
    pos = *(Vec3f*)((char*)object + 0x3C);
    pos.m_x += state->speed;
    pos.m_y += state->time;
    fn_800B6838(object, &pos);

    Vec3f rot;
    rot = *(Vec3f*)((char*)object + 0x48);
    rot.m_x += state->x;
    while (rot.m_x > c[0x9C / 4]) rot.m_x -= c[0xAC / 4];
    while (rot.m_x < c[0xB0 / 4]) rot.m_x += c[0xAC / 4];
    rot.m_y += state->y;
    while (rot.m_y > c[0x9C / 4]) rot.m_y -= c[0xAC / 4];
    while (rot.m_y < c[0xB0 / 4]) rot.m_y += c[0xAC / 4];
    rot.m_z += state->z;
    while (rot.m_z > c[0x9C / 4]) rot.m_z -= c[0xAC / 4];
    while (rot.m_z < c[0xB0 / 4]) rot.m_z += c[0xAC / 4];
    fn_800B6F6C(object, &rot);

    if (*(int*)((char*)self + 0x594) <= 0 && pos.m_y < c[0xB4 / 4]) {
        unsigned int sound = *(unsigned int*)((char*)self + 0x5A0);
        if (sound != 0xFFFFFFFFU) {
            fn_80075F1C(g_sndSystem, sound, 0);
            *(unsigned int*)((char*)self + 0x5A0) = 0xFFFFFFFFU;
        }
    }

    return !(pos.m_y < c[0xB8 / 4]);
}
