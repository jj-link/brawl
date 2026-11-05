#include <mt/mt_vector.h>
#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

inline void Vec3fAdd(REG_ Vec3f* pOut, REG_ const Vec3f* lhs,
                     REG_ const Vec3f* rhs) {
    REG_ f32 fr3, fr2, fr1, fr0;

    // clang-format off
    ASM_ {
        psq_l  fr3, Vec3f.m_x(lhs),   0, 0
        psq_l  fr1, Vec3f.m_x(rhs),   0, 0
        psq_l  fr2, Vec3f.m_z(lhs),   1, 0
        psq_l  fr0, Vec3f.m_z(rhs),   1, 0
        ps_add fr1, fr3, fr1
        ps_add fr0, fr2, fr0
        psq_st fr1, Vec3f.m_x(pOut), 0, 0
        psq_st fr0, Vec3f.m_z(pOut), 1, 0
    }
    // clang-format on
}

extern "C" void fn_110_16130(Vec3f* a, const Vec3f* b, const Vec3f* c) {
    Vec3fAdd(a, b, c);
}
