#pragma force_active on
typedef int s32;
typedef short s16;

extern char *lbl_805A0B70;

void fn_802097C4(s32 arg0) {
    s32 *p = (s32 *)(lbl_805A0B70 + arg0 * 0x44);

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = -0x3C0;
    p[6] = -0x3C0;
    p[7] = -0x3C0;
    p[8] = -0x3C0;
    *(s16 *)((char *)p + 0x40) = 0;
    *(s16 *)((char *)p + 0x3C) = 0;
    *(s16 *)((char *)p + 0x38) = 0;
    *(s16 *)((char *)p + 0x34) = 0;
    *(s16 *)((char *)p + 0x30) = 0;
    *(s16 *)((char *)p + 0x2C) = 0;
    *(s16 *)((char *)p + 0x28) = 0;
    *(s16 *)((char *)p + 0x24) = 0;
}
