#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct FtKoopaDst {
    u32 header[2];
    Vec2f value;
};

extern "C" void fn_102_1B788(FtKoopaDst* dst, const Vec2f* src) {
    dst->value.m_x = src->m_x;
    dst->value.m_y = src->m_y;
}
