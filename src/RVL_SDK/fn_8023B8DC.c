#pragma force_active on
extern unsigned char lbl_80529CF8[];
extern char lbl_80480F40[];
extern char lbl_8059EDFC[5];
extern char lbl_8059EE04[6];
extern void fn_802319FC(int, const char *, const char *);
extern unsigned char fn_802461EC(void *, int);

int fn_8023B8DC(void *arg0, int arg1)
{
    char local[6];
    int all = 0;
    if (*(int *)(lbl_80529CF8 + 0x570) != 0)
        return 2;
    if (arg0 == 0) {
        all = 1;
        arg0 = local;
    }
    if (lbl_80529CF8[0x27c0] >= 4) {
        fn_802319FC(0xd0003, lbl_80480F40, all ? lbl_8059EDFC : lbl_8059EE04);
    }
    *(int *)(lbl_80529CF8 + 0x570) = arg1;
    if (fn_802461EC(arg0, all) == 0)
        return 3;
    return 0;
}
