#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void fn_8003E6DC(const Matrix* mtx, Vec3f* vec);
extern float lbl_27_rodata_30;
}

struct Fn27Obj {
    Vec3f a;
    float f;
    char pad[0x34 - 0x10];
    Vec3f b;
    Matrix m;
    Vec3f p;
};

extern "C" void fn_27_1C80(Fn27Obj* self, const Vec3f* src1, const Vec3f* src2, const Matrix* mat, float f) {
    self->a.m_x = src1->m_x;
    self->a.m_y = src1->m_y;
    self->a.m_z = src1->m_z;
    self->f = f;
    self->b.m_x = src2->m_x;
    self->b.m_y = src2->m_y;
    self->b.m_z = src2->m_z;
    if (mat != NULL) {
        self->m = *mat;
        fn_8003E6DC(&self->m, &self->p);
    } else {
        self->m.setIdentity();
        float one = lbl_27_rodata_30;
        self->p.m_z = one;
        self->p.m_y = one;
        self->p.m_x = one;
    }
}
