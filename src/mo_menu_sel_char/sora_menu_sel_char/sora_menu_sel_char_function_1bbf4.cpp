#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct MuObject;

struct SoraMenuSelCharTarget {
    u8 pad4[4];
    MuObject* model;
};

extern "C" {
extern float lbl_10_rodata_870;
void fn_800B6838(MuObject*, const Vec3f*);
}

extern "C" void fn_10_1BBF4(SoraMenuSelCharTarget* target, const Vec2f* position) {
    Vec3f offset;
    float y = position->m_y;
    offset.m_x = position->m_x;
    offset.m_y = y;
    offset.m_z = lbl_10_rodata_870;
    fn_800B6838(target->model, &offset);
}
