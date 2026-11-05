#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void fn_41_4D14(Vec3f*, const Vec3f*, const Vec3f*);
void fn_8003DF50(Vec3f*, const Vec3f*, float, Vec3f*);
int fn_41_44128(Vec3f*);
void fn_41_534C(Vec3f*, const Vec3f*);
float fn_8003DF9C(const Vec3f*, const Vec3f*);
void fn_41_441BC(Vec2f*, float, float);
void fn_8003DBA8(Vec2f*);
}
extern Vec3f lbl_41_bss_470;
extern Vec3f lbl_41_bss_47C;
extern const float lbl_41_rodata_F78;

extern "C" unsigned long long fn_41_43FB8(const Vec3f* a, const Vec3f* b, float angle, Vec3f* direction) {
    Vec3f difference;
    Vec3f negative;
    Vec3f positive;
    Vec2f result;
    fn_41_4D14(&difference, a, b);
    fn_8003DF50(direction, &lbl_41_bss_470, lbl_41_rodata_F78 * -angle, &negative);
    fn_8003DF50(direction, &lbl_41_bss_470, lbl_41_rodata_F78 * angle, &positive);
    if (fn_41_44128(direction) == 0)
        fn_41_534C(direction, &lbl_41_bss_47C);
    if (fn_41_44128(&difference) == 0)
        fn_41_534C(&difference, &lbl_41_bss_47C);
    float distance = fn_8003DF9C(direction, &difference);
    if (distance <= fn_8003DF9C(direction, &positive)) {
        fn_41_441BC(&result, difference.m_x, difference.m_y);
    } else {
        float negativeDistance = fn_8003DF9C(&negative, &difference);
        if (negativeDistance <= fn_8003DF9C(&positive, &difference))
            fn_41_441BC(&result, negative.m_x, negative.m_y);
        else
            fn_41_441BC(&result, positive.m_x, positive.m_y);
    }
    fn_8003DBA8(&result);
    return *(unsigned long long*)&result;
}
