#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

struct AppName {
    u8 c[5];
};

extern int lbl_805A0630;
extern u8 *lbl_8059E9A8;
extern struct AppName lbl_805A0658;

u8 *OSGetAppGamename(void) {
    u8 *p = (u8 *)0x80003194;
    s8 s;

    if (lbl_805A0630 != 0) {
        p = lbl_8059E9A8;
    } else {
        s = *(s8 *)0x80003194;
        if (s < 0x30 || (s > 0x39 && s < 0x41) || s > 0x5A) {
            p = (u8 *)0x80003180;
        }
    }
    lbl_805A0658.c[0] = p[0];
    lbl_805A0658.c[1] = p[1];
    lbl_805A0658.c[2] = p[2];
    lbl_805A0658.c[3] = p[3];
    lbl_805A0658.c[4] = 0;
    return lbl_805A0658.c;
}
