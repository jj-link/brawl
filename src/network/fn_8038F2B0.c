#include <types.h>
#include <lib/BrawlHeaders/OpenRVL/include/revolution/OS/OSError.h>
#pragma force_active on

extern char lbl_80491340[];

int fn_8038F2B0(int err, int arg1)
{
    if (err >= 0) {
        return 0;
    }

    switch (err) {
    case -0x2D:
        return (int)0xFFFF3BE8;

    case -0x1C:
        return (int)0xFFFF3B84;

    case -0x3E:
        return (int)0xFFFF3B20;

    case -0x6F:
        return (int)0xFFFF3224;

    case -0x79:
        if (arg1 >= 0x14 && arg1 < 0x1E) {
            return (int)0xFFFF3738;
        }
        return (int)0xFFFF38C8;

    case -0x70:
    case -0x4C:
    case -0x30:
    case -0x27:
        if (arg1 >= 0x14 && arg1 < 0x1E) {
            return (int)0xFFFF3738;
        }
        return (int)0xFFFF379C;

    case -0x66:
    case -0x65:
    case -0x64:
        return (int)0xFFFF34E0;

    case (int)0x80000000:
        return (int)0xFFFF3C4C;

    default:
        OSReport(&lbl_80491340[0], err);
        return (int)0xFFFF3C4C;
    }
}
