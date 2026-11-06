#pragma force_active on
extern void *fn_8035DFE8(int size);
extern void fn_803732E0(void *arg0, void *arg1);
extern void *memset(void *dst, int c, unsigned long n);
extern char lbl_8048F840[];

int fn_80370D6C(void *arg0, void **arg1, int arg2) {
    int *obj;
    int *buf;

    obj = fn_8035DFE8(0x14C);
    if (obj == 0) {
        fn_803732E0(arg0, lbl_8048F840);
        return 1;
    }
    memset(obj, 0, 0x14C);
    obj[0] = arg2;
    obj[1] = -1;
    obj[2] = 0;
    obj[4] = 0;
    obj[5] = 0;
    obj[3] = 0;
    obj[8] = 0;
    obj[9] = 0;
    obj[7] = 0x1000;
    buf = fn_8035DFE8(0x1001);
    obj[6] = (int)buf;
    if (buf == 0) {
        fn_803732E0(arg0, lbl_8048F840);
        return 1;
    }
    obj[80] = 0;
    obj[81] = 0;
    *arg1 = obj;
    return 0;
}
