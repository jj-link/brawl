#pragma force_active on
typedef int s32;
typedef unsigned char u8;
extern char lbl_80486048[];
extern void *lbl_805A0E98;
void OSCreateAlarm(void *alarm);
s32 fn_80210708(s32 a, void *b);

void *fn_8027AFB0(char *arg0, s32 arg1) {
    char *p;
    s32 i;

    *(char **)(arg0 + 0x1F0) = lbl_80486048;
    lbl_805A0E98 = arg0;
    if (arg1 != 0) {
        arg0[0x1EC] = (fn_80210708(arg1, arg0 + 0x1D0) != 0);
    } else {
        arg0[0x1EC] = 0;
    }
    OSCreateAlarm(arg0 + 0x1A0);
    p = arg0;
    i = 0;
    do {
        OSCreateAlarm(p);
        *(s32 *)(p + 0x50) = 0;
        i++;
        *(s32 *)(p + 0x58) = -1;
        p[0x5C] = 1;
        p[0x62] = 1;
        p += 0x68;
    } while (i < 4);
    return arg0;
}
