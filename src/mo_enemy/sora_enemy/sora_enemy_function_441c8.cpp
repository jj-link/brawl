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
void Report__14wnemCommonProcFPCce(const char*, ...);
}

extern Vec3f lbl_41_bss_470;
extern Vec3f lbl_41_bss_47C;
extern const char lbl_41_data_E4D8[];
extern const char lbl_41_data_E50E[];

extern "C" unsigned long long fn_41_441C8(const Vec3f* a, const Vec3f* b, float* angle, Vec3f* direction, unsigned char* flag, float f1, float f2, float f3, float f4) {
    Vec3f diff;
    Vec3f neg;
    Vec3f pos;
    Vec2f result;

    fn_41_4D14(&diff, a, b);
    fn_8003DF50(direction, &lbl_41_bss_470, 0.0174532925f * -*angle, &neg);
    fn_8003DF50(direction, &lbl_41_bss_470, 0.0174532925f * *angle, &pos);
    *flag = 0;
    if (*angle <= 1.125f) {
        *angle = *angle + f1 * f4;
        if (*angle <= f3)
            *angle = f3;
        fn_41_441BC(&result, direction->m_x, direction->m_y);
        fn_8003DBA8(&result);
        return *(unsigned long long*)&result;
    } else {
        if (fn_41_44128(direction) == 0) {
            Report__14wnemCommonProcFPCce(lbl_41_data_E4D8);
            fn_41_534C(direction, &lbl_41_bss_47C);
        }
        if (fn_41_44128(&diff) == 0) {
            Report__14wnemCommonProcFPCce(lbl_41_data_E50E);
            fn_41_534C(&diff, &lbl_41_bss_47C);
        }
        float d1 = fn_8003DF9C(direction, &diff);
        if (d1 <= fn_8003DF9C(direction, &pos)) {
            fn_41_441BC(&result, diff.m_x, diff.m_y);
            *angle = *angle - f1;
            if (*angle <= f2)
                *angle = f2;
        } else {
            float d2 = fn_8003DF9C(&neg, &diff);
            float d3 = fn_8003DF9C(&pos, &diff);
            *angle = *angle + f1 * f4;
            if (*angle <= f3)
                *angle = f3;
            if (*angle >= 0.65f * f3)
                *flag = 1;
            if (d2 <= d3) {
                fn_41_441BC(&result, neg.m_x, neg.m_y);
            } else {
                fn_41_441BC(&result, pos.m_x, pos.m_y);
            }
        }
    }
    fn_8003DBA8(&result);
    return *(unsigned long long*)&result;
}
