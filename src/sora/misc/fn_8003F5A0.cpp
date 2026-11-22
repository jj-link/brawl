#include <types.h>
#include <math.h>
#include <mt/mt_matrix.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" const float lbl_805A1728;
extern "C" const float lbl_805A172C;
extern "C" const float lbl_805A1738;

#pragma optimizewithasm off
void Matrix::inverse(Matrix* arg0) const {
    f32 det = (((m[2][1] * (m[0][2] * m[1][0])) + ((m[2][2] * (m[0][0] * m[1][1])) + (m[2][0] * (m[0][1] * m[1][2])))) -
               (m[0][2] * (m[2][0] * m[1][1]))) -
              (m[2][2] * (m[1][0] * m[0][1]));
    det = det - (m[1][2] * (m[0][0] * m[2][1]));

    if ((f32)fabs(det) < lbl_805A1738) {
        register f32 p0, p1;
        register f32 zero = lbl_805A1728;
        register f32 one = lbl_805A172C;
        register f32* d = (f32*)arg0;
        asm { ps_merge00 p1, one, zero }
        asm { ps_merge00 p0, zero, one }
        asm { psq_st p1, 0(d), 0, 0 }
        asm { psq_st zero, 8(d), 0, 0 }
        asm { psq_st p0, 16(d), 0, 0 }
        asm { psq_st zero, 24(d), 0, 0 }
        asm { psq_st zero, 32(d), 0, 0 }
        asm { psq_st p1, 40(d), 0, 0 }
        return;
    }

    f32 c7, c6, c5, c4, c2, c1, inv;
    inv = lbl_805A172C / det;

    Matrix tmp(true);
    const Matrix* src = this;
    if (this == arg0) {
        tmp = *this;
        src = &tmp;
    }

    f32 c0 = inv * ((src->m[1][1] * src->m[2][2]) - (src->m[2][1] * src->m[1][2]));
    arg0->m[0][0] = c0;
    c1 = inv * -((src->m[0][1] * src->m[2][2]) - (src->m[2][1] * src->m[0][2]));
    arg0->m[0][1] = c1;
    c2 = inv * ((src->m[0][1] * src->m[1][2]) - (src->m[1][1] * src->m[0][2]));
    arg0->m[0][2] = c2;
    f32 c3 = inv * -((src->m[1][0] * src->m[2][2]) - (src->m[2][0] * src->m[1][2]));
    arg0->m[1][0] = c3;
    c4 = inv * ((src->m[0][0] * src->m[2][2]) - (src->m[2][0] * src->m[0][2]));
    arg0->m[1][1] = c4;
    c5 = inv * -((src->m[0][0] * src->m[1][2]) - (src->m[1][0] * src->m[0][2]));
    arg0->m[1][2] = c5;
    c6 = inv * ((src->m[1][0] * src->m[2][1]) - (src->m[2][0] * src->m[1][1]));
    arg0->m[2][0] = c6;
    c7 = inv * -((src->m[0][0] * src->m[2][1]) - (src->m[2][0] * src->m[0][1]));
    arg0->m[2][1] = c7;
    f32 c8 = inv * ((src->m[0][0] * src->m[1][1]) - (src->m[1][0] * src->m[0][1]));
    arg0->m[2][2] = c8;

    arg0->m[0][3] = ((-c0 * m[0][3]) - (c1 * m[1][3])) - (c2 * m[2][3]);
    arg0->m[1][3] = ((-c3 * m[0][3]) - (c4 * m[1][3])) - (c5 * m[2][3]);
    f32 t = (-c6 * m[0][3]) - (c7 * m[1][3]);
    arg0->m[2][3] = t - (c8 * m[2][3]);
}
