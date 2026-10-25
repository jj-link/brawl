#include <gf/gf_pad_system.h>
#pragma force_active on

struct PadStatus {
    unsigned int _0[3];
    unsigned int buttons;
    unsigned char pad[0x28];
    signed char error;
    unsigned char pad2[3];
    int type;
};

struct MenuTour {
    unsigned char pad[0x6C];
    int flags;
};

extern "C" int fn_3_86FC(MenuTour* self, int value) {
    int flags = self->flags;
    int port = 0;
    PadStatus status;
    for (; port < 8; ++port) {
        g_gfPadSystem->getSysPadStatus(port, (gfPadStatus*)&status);
        if (status.error < 0)
            continue;
        switch (status.type) {
        case 2:
            if (status.buttons & 0x80000)
                flags |= 2;
            break;
        case 3:
            if (status.buttons & 0x40000)
                flags |= 2;
            break;
        }
    }
    int direction;
    if ((flags & 1) || (flags & 4))
        direction = 0;
    else if ((flags & 2) || (flags & 8))
        direction = 1;
    else
        return value;
    switch (value) {
    case 14:
        return 0xF;
    case 15:
        return 0xE;
    case 3:
        return 4;
    case 4:
        return 3;
    case 27:
        return direction == 1 ? 0x1C : 0x1E;
    case 28:
        return direction == 1 ? 0x1D : 0x1B;
    case 29:
        return direction == 1 ? 0x1E : 0x1C;
    case 30:
        return direction == 1 ? 0x1B : 0x1D;
    default:
        return value;
    }
}
