#include <gm/gm_global.h>
#pragma force_active on

extern "C" int fn_80055398(int offset) {
    unsigned char c = *((const unsigned char*)(g_GameGlobal->m_record) + offset + 0x1528);
    return (unsigned)__cntlzw(c - 2) >> 5;
}
