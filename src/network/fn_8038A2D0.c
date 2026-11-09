#pragma force_active on

extern int lbl_805A1048;
extern int lbl_8059FBC8;
extern char *strcpy(char *, const char *);
extern void *fn_8035A460(int, int, int);
extern void fn_80388590(void *);
extern unsigned int fn_8035D728(void);
extern void fn_803F8C5C(int);
extern void fn_8035D720(void);

void fn_8038A2D0(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, void (*arg6)(void), void *arg7)
{
    char *p;

    if (arg5 != 0 || lbl_805A1048 == 1) {
        p = (char *)arg0;
        *(int *)p = 1;
        *(int *)(p + 0x4) = (int)fn_8035A460(4, 0x64, 0);
        *(int *)(p + 0x7d8) = 0;
        fn_80388590(arg0);
        strcpy(p + 0xc, (const char *)arg1);
        strcpy(p + 0x30, (const char *)arg2);
        strcpy(p + 0x54, (const char *)arg3);
        *(void **)(p + 0x488) = arg6;
        *(int *)(p + 0x48c) = 0;
        *(void **)(p + 0x494) = arg7;
        *(int *)(p + 0x6a4) = 0;
        *(int *)(p + 0x6b4) = -1;
        *(int *)(p + 0x7c) = 0;
        *(int *)(p + 0x80) = 0;
        *(int *)(p + 0x8) = 0;
        *(int *)(p + 0x484) = -1;
        *(int *)(p + 0x480) = 0;
        *(int *)(p + 0x6a8) = 0;
        *(int *)(p + 0x6bc) = arg4;
        strcpy(p + 0x498, (const char *)&lbl_8059FBC8);
        strcpy(p + 0x59c, (const char *)&lbl_8059FBC8);
        *(int *)(p + 0x6b0) = (int)&lbl_8059FBC8;
        *(int *)(p + 0x7d4) = 0;
        *(short *)(p + 0x7d0) = 0x80;
        fn_803F8C5C(fn_8035D728());
        fn_8035D720();
    }
}
