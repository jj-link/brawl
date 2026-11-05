#include <types.h>
#include <gf/gf_pad_system.h>
#pragma force_active on

extern "C" void fn_80219F60(int);

void gfPadSystem::disconectWiiControler() {
    char* pad = (char*)this + 0x100;
    int idx = 0;
    for (u32 i = 4; i < 8; i++) {
        if (*(s8*)(pad + 0x27c) == 0) {
            fn_80219F60(idx);
        }
        idx++;
        pad += 0x40;
    }
}
