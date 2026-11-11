#pragma force_active on

#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>

extern const float lbl_27_rodata_2B80[];

static inline float distance(const Vec2f& point, const Vec2f& center)
{
    Vec2f difference;
    difference.m_x = point.m_x - center.m_x;
    difference.m_y = point.m_y - center.m_y;
    float square = difference.m_x * difference.m_x + difference.m_y * difference.m_y;
    if ((float)(double)nw4r::math::FAbs(square) <= lbl_27_rodata_2B80[28])
        return lbl_27_rodata_2B80[2];
    return square * rsqrtf(square);
}

extern "C" void fn_27_1EF144(
    char* self, void** arg1, Vec2f* arg2, float* arg3, char* target)
{
    float scale = lbl_27_rodata_2B80[33];
    void** out = arg1;
    Vec2f* positions = arg2;
    float* distances = arg3;
    char* current = *(char**)(self + 0x34C);
    Vec2f center =
        (*(Vec2f*)(target + 0x18) + *(Vec2f*)(target + 0x20)) * scale;

    for (int i = 0; i < *(unsigned short*)(self + 0x350);
         out++, positions++, distances++, i++, current += 0x4C) {
        if (!(*(int*)(current + 0x40) & 2)) {
            *out = 0;
        } else {
            *out = current;

            if (current == target) {
                positions->m_x = scale *
                    (((Vec2f*)(current + 0x18))->m_x +
                     ((Vec2f*)(current + 0x20))->m_x);
                positions->m_y = scale *
                    (((Vec2f*)(current + 0x18))->m_y +
                     ((Vec2f*)(current + 0x20))->m_y);
                *distances = lbl_27_rodata_2B80[2];
            } else {
                float d1 = distance(*(Vec2f*)(current + 0x18), center);
                float d2 = distance(*(Vec2f*)(current + 0x20), center);

                if (d1 < d2) {
                    positions->m_x = ((Vec2f*)(current + 0x18))->m_x;
                    positions->m_y = ((Vec2f*)(current + 0x18))->m_y;
                    *distances = d1;
                } else {
                    positions->m_x = ((Vec2f*)(current + 0x20))->m_x;
                    positions->m_y = ((Vec2f*)(current + 0x20))->m_y;
                    *distances = d2;
                }
            }
        }
    }
}
