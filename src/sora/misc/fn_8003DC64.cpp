#include <mt/mt_vector.h>
#include <revolution/MTX/mtx.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern const float lbl_805A1708;
extern const float lbl_805A170C;
extern const float lbl_805A1710;
extern const float lbl_805A1714;
extern const float lbl_805A1718;
extern const float lbl_805A171C;

extern "C" void fn_8003F8FC(Quaternion*, const Vec3f*, float);
extern "C" void fn_8003FA14(const Quaternion*, const Vec3f*, Vec3f*);

extern "C" void fn_8003DC64(const Vec2f* input, float angle, Vec2f* output) {
    unsigned int zero = 0;
    int test = 0;
    if ((float)(double)nw4r::math::FAbs(input->m_x) < lbl_805A1708) {
        test = 1;
    }
    if (test != 0) {
        test = 0;
        if ((float)(double)nw4r::math::FAbs(input->m_y) < lbl_805A1708) {
            test = 1;
        }
        if (test != 0) {
            zero = 1;
        }
    }
    if (zero == 1) {
        Vec2f v(lbl_805A170C, lbl_805A170C);
        *output = v;
        return;
    }
    unsigned int small = 0;
    if ((float)(double)nw4r::math::FAbs(angle) < lbl_805A1708) {
        small = 1;
    }
    if (small == 1) {
        *output = *input;
        return;
    }
    float absAngle = (float)(double)nw4r::math::FAbs(angle);
    Quaternion q;
    Vec3f axis(lbl_805A170C, lbl_805A170C, lbl_805A1710);
    Vec3f v(input->m_x, input->m_y, lbl_805A170C);
    Vec3f result;
    if (absAngle > lbl_805A1714) {
        while (angle > lbl_805A1714) {
            angle -= lbl_805A1718;
        }
        while (angle < lbl_805A171C) {
            angle += lbl_805A1718;
        }
    }
    fn_8003F8FC(&q, &axis, angle);
    fn_8003FA14(&q, &v, &result);
    output->m_x = result.m_x;
    output->m_y = result.m_y;
}
