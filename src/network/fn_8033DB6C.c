#pragma force_active on
extern int lbl_805A0FA8;
extern void fn_8034AA48(void);
extern int fn_803894EC(int, int, int, int, int, int, int, void *, int);
extern int fn_80349F28(int);
extern void fn_8034296C(int, int, int, int);
extern int fn_8033CD90(int);
extern int fn_8034DCF0(void);
extern void fn_80379148(int);
extern void *memcpy(void *, const void *, unsigned long);
extern unsigned long long OSGetTime(void);

int fn_8033DB6C(int arg0, int arg1, int arg2, int arg3, int arg4, unsigned char arg5, int arg6, void *arg7, int arg8) {
    unsigned int sp10;
    int p;
    unsigned long long t;

    p = lbl_805A0FA8;
    if (*(int *)(p + 0xF8) == 0) {
        int tmp = *(int *)(p + 0x30C);
        *(int *)(p + 0xF8) = fn_803894EC(tmp, tmp, *(int *)(p + 0x310), 0, 0x14, 1, 0, (void *)fn_8034AA48, 0);
    }
    if (*(int *)(lbl_805A0FA8 + 0xF8) == 0 && fn_80349F28(5) != 0) {
        return -1;
    }
    memcpy(&sp10, arg7, 4);
    fn_8034296C(3, 0, arg1, arg2);
    *(int *)(lbl_805A0FA8 + 0x4A0) = arg0;
    *(unsigned char *)(lbl_805A0FA8 + 0x4A4) = 0;
    *(unsigned char *)(lbl_805A0FA8 + 0x4A5) = arg5;
    *(int *)(lbl_805A0FA8 + 0x4C8) = arg6;
    memcpy((void *)(lbl_805A0FA8 + 0x4CC), &sp10, 4);
    *(int *)(lbl_805A0FA8 + 0x554) = arg8;
    if (*(int *)(lbl_805A0FA8 + 0x10) == 0 && fn_8033CD90(*(int *)(lbl_805A0FA8 + 0x218)) != 0) {
        return 0;
    }
    if (*(int *)(lbl_805A0FA8 + 0x30) != 0 && *(unsigned short *)(lbl_805A0FA8 + 0x2E) != 0) {
        if (fn_8034DCF0() == 0) {
            return 0;
        }
    } else {
        *(int *)(lbl_805A0FA8 + 0x1B4) = 0xE;
        t = OSGetTime();
        p = lbl_805A0FA8;
        *(unsigned int *)(p + 0x214) = (unsigned int)t;
        *(unsigned int *)(p + 0x210) = (unsigned int)(t >> 32);
    }
    *(int *)(lbl_805A0FA8 + 0x480) = arg1;
    *(int *)(lbl_805A0FA8 + 0x484) = arg2;
    *(int *)(lbl_805A0FA8 + 0x488) = arg3;
    *(int *)(lbl_805A0FA8 + 0x48C) = arg4;
    *(unsigned char *)(lbl_805A0FA8 + 0x15) = 3;
    *(unsigned char *)(lbl_805A0FA8 + 0x17) = 1;
    fn_80379148(*(int *)(lbl_805A0FA8 + 0x10));
    *(unsigned char *)(lbl_805A0FA8 + 0x1C1) = 0;
    t = OSGetTime();
    p = lbl_805A0FA8;
    *(unsigned int *)(p + 0x214) = (unsigned int)t;
    *(unsigned int *)(p + 0x210) = (unsigned int)(t >> 32);
    return 1;
}
