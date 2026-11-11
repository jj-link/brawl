#pragma force_active on
extern char lbl_8048AA60[], lbl_805338B0[];
extern char lbl_8059F0E8[8], lbl_8059F15C[1];
void fn_80335638(int, const char *, ...);
int fn_8038897C(void *), fn_803889A8(void *), fn_8038892C(void *), fn_80388958(void *), fn_80388970(void *);
unsigned short fn_803889B0(void *), fn_80388960(void *);
int fn_80388794(void *, void *, int);
int fn_80388738(void *, int, const char *);
void fn_8034B17C(void *arg0) {
    char *base = lbl_8048AA60;
    char *p;
    int i;
    fn_80335638(0x400, base + 0x1f54, fn_8038897C(arg0));
    fn_80335638(0x400, base + 0x1f78, fn_803889A8(arg0));
    fn_80335638(0x400, base + 0x1f9c, fn_803889B0(arg0));
    fn_80335638(0x400, base + 0x1fc0, fn_8038892C(arg0));
    fn_80335638(0x400, base + 0x1fe4, fn_80388958(arg0));
    fn_80335638(0x400, base + 0x2008, fn_80388960(arg0));
    fn_80335638(0x400, base + 0x202c, fn_80388970(arg0));
    fn_80335638(0x400, base + 0x2050, fn_80388794(arg0, base + 0x1eb8, -1));
    fn_80335638(0x400, base + 0x2064, fn_80388794(arg0, base + 0x1ec4, -1));
    fn_80335638(0x400, base + 0x2078, lbl_8059F0E8, fn_80388794(arg0, lbl_8059F0E8, 0));
    fn_80335638(0x400, base + 0x2088, base + 0x178, fn_80388794(arg0, base + 0x178, -1));
    fn_80335638(0x400, base + 0x2094, base + 0x16c, fn_80388794(arg0, base + 0x16c, -1));
    fn_80335638(0x400, base + 0x2094, base + 0x160, fn_80388794(arg0, base + 0x160, -1));
    fn_80335638(0x400, base + 0x2094, base + 0xd0c, fn_80388794(arg0, base + 0xd0c, -1));
    fn_80335638(0x400, base + 0x2094, base + 0xd18, fn_80388794(arg0, base + 0xd18, -1));
    fn_80335638(0x400, base + 0x2094, base + 0xd24, fn_80388794(arg0, base + 0xd24, -1));
    fn_80335638(0x400, base + 0x2094, base + 0xd34, fn_80388794(arg0, base + 0xd34, -1));
    i = 0;
    p = lbl_805338B0;
    do {
        if (((unsigned char *)p)[0]) {
            if (((unsigned char *)p)[1])
                fn_80335638(0x400, base + 0x20a0, *(int *)(p + 4), fn_80388738(arg0, *(int *)(p + 4), lbl_8059F15C));
            else
                fn_80335638(0x400, base + 0x20ac, *(int *)(p + 4), fn_80388794(arg0, (void *)*(int *)(p + 4), -1));
        }
        i++;
        p += 12;
    } while (i < 0x9a);
}