#include <mt/mt_vector.h>
#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

inline void Vec3fAdd(REG_ Vec3f* pOut, REG_ const Vec3f* lhs,
                     REG_ const Vec3f* rhs) {
    REG_ f32 f3, f2, f1, f0;

    // clang-format off
    ASM_ {
        psq_l  f0, Vec3f.m_x(lhs),   0, 0
        psq_l  f2, Vec3f.m_x(rhs),   0, 0
        psq_l  f1, Vec3f.m_z(lhs),   1, 0
        psq_l  f3, Vec3f.m_z(rhs),   1, 0
        ps_add f0, f0, f2
        ps_add f1, f1, f3
        psq_st f0, Vec3f.m_x(pOut), 0, 0
        psq_st f1, Vec3f.m_z(pOut), 1, 0
    }
    // clang-format on
}

extern "C" void fn_41_1BEBC(const Vec3f* lhs, const Vec3f* rhs, Vec3f* pOut)
{
    Vec3fAdd(pOut, lhs, rhs);
}
