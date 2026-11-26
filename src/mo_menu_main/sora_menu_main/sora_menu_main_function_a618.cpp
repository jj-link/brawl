#include <types.h>
#include <mt/mt_matrix.h>
#pragma force_active on

extern "C" {
extern char lbl_2_data_EF0[];
extern float lbl_2_rodata_2A0;

void fn_800B6E84(Vec3f*, void*);
Matrix fn_800B6B34(void*, const char*);
}

struct Obj {
    char pad[0x48];
    Vec3f rot;
};

struct Self {
    char pad[0xe8];
    Obj* objs[117];
};

extern "C" void fn_2_A618(Matrix* out, Self* self, int index) {
    u32 base = (u32)lbl_2_data_EF0;
    Obj* obj = self->objs[index + 4];

    Vec3f rot;
    rot = obj->rot;
    Vec3f scale;
    Vec3f raw;
    Vec3f pos;

    fn_800B6E84(&raw, obj);
    scale = raw;
    pos.m_x = lbl_2_rodata_2A0;
    pos.m_y = lbl_2_rodata_2A0;
    pos.m_z = lbl_2_rodata_2A0;

    Matrix result(true);
    result.setSRT(scale, rot, pos);

    Matrix temp(true);
    temp = fn_800B6B34(obj, (const char*)(base + 0x37c));
    result.mul(&temp, &result);
    temp = fn_800B6B34(obj, (const char*)(base + 0x384));
    result.mul(&temp, &result);
    temp = fn_800B6B34(obj, (const char*)(base + 0x2c0));
    result.mul(&temp, &result);

    *out = result;
}
