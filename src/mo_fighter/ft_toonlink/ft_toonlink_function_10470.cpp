#include <mt/mt_vector.h>
#pragma force_active on

#define REG_ regist##er
#define ASM_ as##m

// Vec3fSub exactly as this module built it: the four pair loads land in fr3/fr1/fr2/fr0
// (the order the register allocator hands out fr3, fr1, fr2, fr0), the two differences
// are written into fr1 and fr0, and both results are stored with those registers.
inline void Vec3fSub_mod(REG_ Vec3f* pOut, REG_ const Vec3f* lhs,
                         REG_ const Vec3f* rhs) {
    REG_ f32 fr3, fr2, fr1, fr0;

    // clang-format off
    ASM_ {
        psq_l  fr3, Vec3f.m_x(lhs),   0, 0
        psq_l  fr1, Vec3f.m_x(rhs),   0, 0
        psq_l  fr2, Vec3f.m_z(lhs),   1, 0
        psq_l  fr0, Vec3f.m_z(rhs),   1, 0
        ps_sub fr1, fr3, fr1
        ps_sub fr0, fr2, fr0
        psq_st fr1, Vec3f.m_x(pOut), 0, 0
        psq_st fr0, Vec3f.m_z(pOut), 1, 0
    }
    // clang-format on
}

extern "C" void fn_121_10470(Vec3f* pOut, const Vec3f* lhs, const Vec3f* rhs)
{
    Vec3fSub_mod(pOut, lhs, rhs);
}
