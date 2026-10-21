#include <types.h>
#pragma force_active on

extern "C" {
extern u8* g_GameGlobal;

int fn_27_25246C() {
    u8* p = *(u8**)(g_GameGlobal + 0x30);
    u8 raw = p[0x5fa];
    if ((s8)raw < 0) {
        return 0;
    }

    int r6 = 0;
    if (((p[0x4924] >> 7) & 1) != 0 &&
        ((p[0x606] >> 7) & 1) != 0) {
        if ((s8)raw != 0) {
            goto end;
        }
        if (((p[0x606] >> 6) & 1) != 0) {
            goto inner_set;
        }
        if (((p[0x606] >> 5) & 1) == 0) {
            goto end;
        }
inner_set:
        r6 = 1;
        goto end;
    }
    if ((s8)raw != 0) {
        goto end;
    }
    if (((p[0x606] >> 6) & 1) == 0) {
        goto end;
    }
    r6 = 1;
end:
    if (r6 != 0) {
        p[0x605] = 3;
        return 1;
    }
    return 0;
}
}
