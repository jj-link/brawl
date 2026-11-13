#pragma force_active on
extern int lbl_805A0FA8;
extern char lbl_8048AA60[];
extern char lbl_8059F120[8];
extern char lbl_8059F128[5];
extern char lbl_8059F130[4];

int fn_803685D0(int a, int b);
void fn_80335638(int level, const char *fmt, ...);
int fn_803437E4(int a, int b, int c, unsigned char *d, int e);
void fn_8034F028(void *dst, const void *src, unsigned int n);
int fn_803688F8(int a, int b, const char *c);
int snprintf(char *s, unsigned int n, const char *fmt, ...);
int strlen(const char *s);
unsigned long long OSGetTime(void);

int fn_80343500(int arg0, int arg1, int arg2, int arg3, unsigned char *arg4, int arg5) {
    char *tbl = lbl_8048AA60;
    char sp218[0x200];
    char sp8[0x10];
    char sp18[0x200];
    int n;
    int i;
    int len;
    unsigned char *p;
    unsigned long long t;
    char *base;
    char *t19;
    char *q;
    int ret = 0;
    int res;

    if (fn_803685D0(*(int *)lbl_805A0FA8, arg1) != 0) {
        fn_80335638(0x200004, tbl + 0xF3C, arg1);
        if (arg4 != 0 && arg5 != 0) {
            ret = snprintf(sp218, 0x200, tbl + 0xF58, arg4[0], arg4[1], arg4[2], arg4[3]);
            p = arg4 + 4;
            for (i = 1; i < arg5; i++) {
                n = snprintf(sp8, 0x10, tbl + 0xF6C, p[0], p[1], p[2], p[3]);
                fn_8034F028(sp218 + ret, sp8, n);
                ret += n;
                p += 4;
            }
        }
        sp218[ret] = 0;
        n = *(int *)lbl_805A0FA8;
        ret = snprintf(sp18, 0x200, lbl_8059F120, lbl_8059F128, 0xb, lbl_8059F130);
        sp18[ret] = (char)arg0;
        t19 = sp18 + 1 + ret;
        *t19 = 0;
        len = strlen(sp218);
        fn_8034F028(t19, sp218, len);
        t19[len] = 0;
        res = fn_803688F8(n, arg1, sp18);
        fn_80335638(0x40, tbl + 0xF80, arg0, arg1);
    } else {
        if (arg2 == 0 && arg3 == 0) {
            fn_80335638(0x200004, tbl + 0xFB0, arg0, arg1);
            q = (char *)lbl_805A0FA8;
            for (i = 0; i < 0x20; i++) {
                if (arg1 == *(int *)(q + 0x108)) {
                    arg2 = *(int *)((char *)lbl_805A0FA8 + i * 4 + 0x38);
                    arg3 = *(unsigned short *)((char *)lbl_805A0FA8 + i * 2 + 0xb8);
                    fn_80335638(0x200004, tbl + 0xFE0, i, (char *)lbl_805A0FA8 + i * 4);
                    break;
                }
                q += 4;
            }
        }
        fn_80335638(0x200004, tbl + 0x100C, arg2, arg3);
        res = fn_803437E4(arg0, arg2, arg3, arg4, arg5);
    }
    if ((unsigned int)arg0 == 2U || (unsigned int)arg0 == 6U || (unsigned char)(arg0 + 0xf8) <= 1U) {
        *(unsigned char *)(lbl_805A0FA8 + 0x3e8) = (unsigned char)arg0;
        *(short *)(lbl_805A0FA8 + 0x3ea) = (short)arg3;
        *(int *)(lbl_805A0FA8 + 0x3ec) = arg2;
        *(int *)(lbl_805A0FA8 + 0x470) = arg1;
        *(int *)(lbl_805A0FA8 + 0x474) = arg5;
        t = OSGetTime();
        base = (char *)lbl_805A0FA8;
        *(unsigned int *)(base + 0x47c) = (unsigned int)t;
        *(unsigned int *)(base + 0x478) = (unsigned int)(t >> 32);
        if (arg4 != 0 && arg5 != 0) {
            fn_8034F028(base + 0x3f0, arg4, arg5 * 4);
        }
    }
    return res;
}
