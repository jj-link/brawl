#include <mt/mt_vector.h>
#include <mt/mt_prng.h>

#pragma force_active on
#pragma fp_contract off
#pragma opt_propagation off

extern const float lbl_34_rodata_0[];
extern "C" void fn_800B6838(void*, const Vec3f*);
extern "C" void fn_800B6F6C(void*, const Vec3f*);

struct AdvResultState {
    int index;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
};

extern "C" void fn_34_1318(void* self, AdvResultState* state) {
    const float* c = lbl_34_rodata_0;
    void* object = ((void**)((char*)self + 0x138))[state->index];
    Vec3f pos;
    pos.m_x = c[34] * randf();
    pos.m_y = c[35];
    pos.m_z = c[36];
    fn_800B6838(object, &pos);
    state->unk8 = c[14];
    state->unk4 = c[37] + randf();
    Vec3f rot;
    rot.m_x = c[38] * (c[39] * randf()) - c[39];
    rot.m_y = c[38] * (c[39] * randf()) - c[39];
    rot.m_z = c[38] * (c[39] * randf()) - c[39];
    fn_800B6F6C(object, &rot);
    state->unkC = c[40] + c[41] * randf();
    state->unk10 = c[40] + c[41] * randf();
    state->unk14 = c[40] + c[41] * randf();
}
