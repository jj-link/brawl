#include "gf/gf_pad_system.h"

#pragma force_active on

extern "C" void maskMotor__11gfPadSystemFUs(gfPadSystem*, unsigned int);

static inline unsigned int getMask(unsigned char* p) {
    unsigned int mask = 0;

    for (int i = 0; i < 4; ++i) {
        if ((p[0xB3 + i * 0x5C] >> 6) & 1) {
            unsigned int port = p[0xD5 + i * 0x5C];
            if (port != 0) {
                mask |= 1U << (port - 1);
            }
        }
    }

    return mask;
}

extern "C" void fn_80110410(unsigned char* p) {
    if (p != 0) {
        maskMotor__11gfPadSystemFUs(g_gfPadSystem, getMask(p) ^ 0xFF);
    } else {
        maskMotor__11gfPadSystemFUs(g_gfPadSystem, 0xFF);
    }
}
