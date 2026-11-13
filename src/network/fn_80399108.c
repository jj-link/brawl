#include <types.h>
#include <string.h>
#pragma force_active on
extern s32 fn_8020AB58(s32 *, s32, s32);
extern s32 fn_803C39BC(s32, s32, s32);
extern s32 fn_803C3F48(const char *);
extern void OSSleepTicks(s64);
extern s32 lbl_805A1170;
extern char lbl_8059FCC8[4];
s32 fn_80399108(s32 arg0, s32 arg1, s32 *arg2)
{
    s32 remaining = arg1;
    u32 offset = arg2[2];
    s32 buffer = lbl_805A1170 + 0xB00;
    u8 *src = (u8 *)arg0;
    s32 r;
    s32 elapsed = 0;
    s32 result = 0;
    while (remaining != 0) {
        u32 chunk = 0x800 - offset;
        if ((u32)remaining < chunk) chunk = remaining;
        memcpy((void *)(buffer + offset), src, chunk);
        offset += chunk;
        remaining -= chunk;
        src += chunk;
        if (offset >= 0x800) {
            offset = 0;
            if (arg2[1] & 0x100) {
                s32 r = fn_803C39BC(arg2[38], buffer, 0x800);
                if (r != 0) {
                    if (r == 5) {
                        switch (fn_803C3F48(lbl_8059FCC8)) {
                        case -5:
                        case -15: result = -0x2E; break;
                        case -4: result = -0x26; break;
                        default: result = -0x13; break;
                        }
                    } else result = -0x13;
                    goto finish;
                }
            } else {
                u32 retries = 0;
                for (retries = 0; retries < 3; retries++) {
                    r = fn_8020AB58(arg2 + 3, buffer, 0x800);
                    if ((u32)(r + 3) > 1) break;
                    {
                        u32 ms = (*(u32 *)0x800000F8 / 4) / 1000;
                        s64 ticks = ((s64)elapsed << 32) | ms;
                        OSSleepTicks(ticks * 1000);
                    }
                }
                if (r == -4) return -0x26;
                if (r != 0x800) {
                    result = -0x13;
                    goto finish;
                }
            }
        }
    }
finish:
    arg2[2] = offset;
    return result;
}