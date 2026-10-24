#include <types.h>
#pragma force_active on

extern "C" long fn_27_22CB50(void* self, unsigned long kind, unsigned long sub) {
    long flags;
    if (kind == 1) {
        flags = 0x10;
    } else if (kind == 3 && sub == 9) {
        flags = 0x10;
    } else {
        flags = 0;
    }
    if ((long)kind == 0 && sub == 5) {
        flags |= 0x80;
    }
    if (kind == 1) {
        flags |= 0x800;
    }
    if (kind == 3) {
        switch (sub) {
        case 1:
        case 2: flags |= 0x1020; break;
        case 3: flags |= 0x20; break;
        case 4: flags |= 3; break;
        case 6: flags |= 0x420; break;
        case 7: flags |= 0x21; break;
        case 8: flags |= 0x40; break;
        case 9: flags |= 2;
        case 0:
        case 5:
        default: break;
        }
    }
    return flags;
}
