#pragma force_active on
extern unsigned char lbl_80529CF8[];
extern char lbl_80480EE8[];
extern char lbl_8059EDFC[5];
extern char lbl_8059EE04[6];
extern void fn_802319FC(int, const char *, const char *);
extern void *fn_8022EFF8(int);
extern void fn_80245FCC(void *, void *, int);

int fn_8023B734(void *arg0, int arg1)
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
        fn_802319FC(0xd0003, lbl_80480EE8, all ? lbl_8059EDFC : lbl_8059EE04);
    }
    {
        void *buf = fn_8022EFF8(2);
        if (buf != 0) {
            *(int *)(lbl_80529CF8 + 0x570) = arg1;
            fn_80245FCC(buf, arg0, all);
            return 0;
        }
    }
    return 3;
}