#include <types.h>
#pragma force_active on

struct FlagObj {
    char padding[0x28];
    unsigned char flags;
};

struct Global {
    FlagObj* m_ptr;
};

extern "C" Global* g_GameGlobal;

extern "C" void fn_80052694() {
    g_GameGlobal->m_ptr->flags |= 0x80;
}
