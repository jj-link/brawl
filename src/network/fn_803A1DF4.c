#pragma force_active on

extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(void *, int, void *);

extern int lbl_8059FDD8;
extern int lbl_805A1170;

int fn_803A1DF4(void **arg0) {
    unsigned char context[0xA0];
    int *p;
    int result;
    int temp;

    p = (int *)(lbl_805A1170 + 0x2A00);
    *arg0 = p;
    if (p[0] != 0x5763466C) {
        result = fn_8039832C(context, lbl_8059FDD8, 2);
        if (result != 0) {
            return result;
        }
        fn_80398818(context, 0, 0);
        temp = fn_80398A08(*arg0, 0x360, context);
        result = fn_80398680(context);
        if (temp != 0) {
            result = temp;
        }
        if (result != 0) {
            return result;
        }
        p = *arg0;
        if (p[0] != 0x5763466C) {
            return -0xE;
        }
        if ((unsigned int)p[1] != 2U) {
            return -0x1B;
        }
    }
    return 0;
}
