#include <st/st_melee.h>
#include <gm/gm_global.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void fn_43_7D0(stMelee* self, Vec3f* out, unsigned int index)
{
    unsigned int mode = (*((unsigned char*)g_GameGlobal->m_modeMelee + 8) >> 2) & 0x3f;
    if (mode == 10 || mode == 16) {
        if (index >= 20) {
            Vec3f* src = (Vec3f*)((char*)self + ((index - 20) % 5) * 12 + 0x1d8);
            out->m_x = src->m_x;
            out->m_y = src->m_y;
            out->m_z = src->m_z;
        } else if (index >= 10) {
            Vec3f* src = (Vec3f*)((char*)self + ((index - 10) % 5) * 12 + 0x214);
            out->m_x = src->m_x;
            out->m_y = src->m_y;
            out->m_z = src->m_z;
        } else {
            Vec3f* src = (Vec3f*)((char*)self + (index % 2) * 12 + 0x244);
            out->m_x = src->m_x;
            out->m_y = src->m_y;
            out->m_z = src->m_z;
        }
    } else {
        self->stMelee::getFighterStartPos(out, index);
    }
}
