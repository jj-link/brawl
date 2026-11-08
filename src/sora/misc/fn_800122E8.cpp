#include <mt/mt_vector.h>
#pragma force_active on
extern "C" void* fn_8001237C(void*, void*, unsigned int, void*);
extern "C" void* fn_800122E8(void* self, unsigned int id, const Vec2f* arg) {
    Vec2f copy;
    copy.m_x = arg->m_x;
    copy.m_y = arg->m_y;
    return fn_8001237C(self, (char*)self + 0x40, id, &copy);
}
