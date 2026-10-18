#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct FtSamusVecHolder {
    u8 pad[0x20];
    Vec2f value;
};

extern "C" void fn_94_10940(FtSamusVecHolder* self, const Vec2f* src) {
    self->value.m_x = src->m_x;
    self->value.m_y = src->m_y;
}
