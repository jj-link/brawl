#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef long long s64;

extern int lbl_805A1158;
extern int lbl_805A1170;
extern char lbl_8059FCC8[4];
extern int fn_803C3920(void *, void *, u32, u32 *);
extern int fn_803C3F48(const char *);
extern u32 fn_8020AA78(void *, void *, u32);
extern void OSSleepTicks(s64);
extern void *memcpy(void *, const void *, u32);

int fn_8039940C(char *out, int size, unsigned char *file)
{
    int remaining;
    u32 request;
    u32 copied;
    u32 got;
    u32 offset;
    unsigned char *buf;
    char *dst;
    int result;
    u32 i;
    u32 sp8;
    int r;

    dst = out;
    remaining = size;
    result = 0;
    buf = (unsigned char *)(lbl_805A1170 + 0x900);

    if (lbl_805A1158 != 0)
        return -0x16;
    lbl_805A1158 = *(int *)file;
    offset = *(u32 *)(file + 8);
    if (offset & 0x80000000)
        return -0x28;
    while (remaining != 0) {
        copied = 0x200 - offset;
        request = 0x200;
        if ((u32)remaining < copied) {
            copied = (u32)remaining;
            request = (remaining + offset + 0x1F) & ~0x1F;
        }
        if (*(u32 *)(file + 4) & 0x100) {
            r = fn_803C3920(*(void **)(file + 0x98), buf, request, &sp8);
            if (r != 0) {
                if (r == 5) {
                    switch (fn_803C3F48(lbl_8059FCC8)) {
                    case -5:
                    case -15:
                        result = -0x2E;
                        break;
                    case -4:
                        result = -0x26;
                        break;
                    default:
                        result = -0x12;
                        break;
                    }
                } else {
                    result = -0x12;
                }
                break;
            }
            got = sp8;
        } else {
            i = 0;
            do {
                got = fn_8020AA78(file + 0xC, buf, request);
                if ((u32)(got + 3) > 1)
                    break;
                OSSleepTicks(1000 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
                i++;
            } while (i < 3);
            if ((int)got == -4)
                return -0x26;
        }
        if (got != request) {
            result = -0x12;
            break;
        }
        memcpy(dst, buf + offset, copied);
        dst += copied;
        remaining -= copied;
        offset = 0;
    }
    *(u32 *)(file + 8) = ((*(u32 *)(file + 8) + (u32)size) & 0x1F) | 0x80000000;
    lbl_805A1158 = 0;
    return result;
}
