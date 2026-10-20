#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_2_36940(void* arg, int freeFlag) {
    u8* bytes = (u8*)arg;

    if (arg != NULL) {
        int i = 0;
        u32* flags = (u32*)((char*)g_GameGlobal->m_record + 0x15ac);
        int bit = 1;

        for (; bit < 1064; bit += 2, i++) {
            if (bytes[0x13d0 + i] == 0) {
                flags[bit / 32] &= ~(1 << (bit % 32));
            }
        }

        if (freeFlag > 0) {
            __dl__FPv(arg);
        }
    }

    return arg;
}
