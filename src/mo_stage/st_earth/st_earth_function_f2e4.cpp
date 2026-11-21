#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void fn_8003F03C(Matrix* m, s32 v, f32 a, f32 b, f32 c);
void fn_8003E6DC(Matrix* m, Vec3f* v);
void fn_8003E828(Matrix* a, Vec3f* b, Matrix* out);
void fn_8003EA50(Matrix* m, Vec3f* v);
void fn_8003F074(Matrix* m, f32 a, f32 b, f32 c);
extern const f32 lbl_66_rodata_1C8[];
}

struct SrcObj {
    char pad[0x28];
    Matrix m;
};

struct Self {
    char pad[0x150];
    u8 b150;
    char pad151[7];
    Matrix m158;
    SrcObj* src;
};

extern "C" void fn_66_F2E4(void* arg0) {
    const f32* c = lbl_66_rodata_1C8;
    Self* self = (Self*)arg0;
    SrcObj* src = self->src;
    if (src != 0) {
        Matrix m60(true);
        Matrix m30(true);
        Vec3f pos, rot, scale;
        m60 = src->m;
        fn_8003F03C(&m30, *(s32*)&m60.m[2][2], c[0], c[1], c[0]);
        m60.mul(&m30, &m60);
        float z = m60.m[2][3];
        float y = m60.m[1][3];
        float x = m60.m[0][3];
        pos.m_y = y;
        pos.m_x = x;
        pos.m_z = z;
        m60.getRotate(&rot);
        fn_8003E6DC(&m60, &scale);
        m60.setIdentity();
        fn_8003F074(&m60, pos.m_x, pos.m_y, pos.m_z);
        fn_8003EA50(&m60, &rot);
        if ((s32)self->b150 != 0x13) {
            scale.m_x = c[2];
            scale.m_y = c[2];
            scale.m_z = c[2];
        }
        fn_8003E828(&m60, &scale, &m60);
        m60.rotY(c[3]);
        self->m158 = m60;
    }
}
