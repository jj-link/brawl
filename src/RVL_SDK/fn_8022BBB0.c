#pragma force_active on
typedef struct { short a, b, c, d; unsigned char e; } Info;
extern unsigned char lbl_804FB4A0[];
extern void fn_8023D97C(int, int, void *);
void fn_8022BBB0(int arg0, short arg1) {
    Info info;
    unsigned char *p = lbl_804FB4A0;
    if (arg1 > 0) {
        info.e = 2;
    } else {
        info.e = 0;
    }
    info.a = arg1;
    info.b = arg1;
    info.c = 1;
    info.d = 0;
    fn_8023D97C(p[0x70a], arg0, &info);
}