#pragma force_active on
extern char lbl_80491778[];
extern int fn_803974FC(void);
extern int fn_80397580(void);
extern char *fn_803970E4(int, int);
extern char *fn_80397564(int);
extern int fn_80396A74(char *, char *, int, char *, char *);
extern void OSReport(const char *, ...);
extern void fn_801D8690(const char *, int, const char *, ...);
extern int fn_803F861C(const char *, ...);

int fn_80396BE4(int arg0) {
    char *base = lbl_80491778;
    int ctx;
    char *p;
    char *q;
    char *user;
    char *pass;
    int ret;

    ctx = fn_803974FC();
    p = fn_803970E4(fn_80397580(), arg0);
    q = fn_80397564(ctx);
    if (*(int *)(p + 8) != 0) {
        q = q + 0x170;
    } else {
        q = q + 0x28;
    }
    if (*(unsigned char *)q == 1) {
        user = 0;
        pass = 0;
        if (*(unsigned char *)(q + 1) == 1) {
            user = q + 0x106;
            pass = q + 0x127;
        }
        OSReport(base + 0x21c, q + 4, *(unsigned short *)(q + 0x104),
                 user ? user : base + 0x210, pass ? pass : base + 0x210);
        ret = fn_80396A74(p, q + 4, *(unsigned short *)(q + 0x104), user, pass);
        if (ret < 0) {
            OSReport(base + 0x240, ret);
            fn_801D8690(base + 0x25c, 0x37d, base + 0x268);
        } else {
            return 0;
        }
    } else {
        fn_803F861C(base + 0x278);
    }
    return -1;
}
