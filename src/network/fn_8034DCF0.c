#pragma force_active on
extern char *lbl_805A0FA8;
extern void fn_803898B0(void *);
extern int fn_80346D80(int, int, int);
extern int fn_80349F28();
extern int fn_80349C88();
extern int fn_803685D0(int, int);
extern int fn_80346B10(int, int);
extern int fn_80342BA8(int);

static inline unsigned char getMode(void)
{
    return *(unsigned char *)(lbl_805A0FA8 + 0x16);
}

static inline unsigned char getModeP(char *p)
{
    return *(const unsigned char *)(p + 0x16);
}

int fn_8034DCF0(void)
{
    int ret;
    int m;
    int val = *(int *)(lbl_805A0FA8 + 0xf8);

    if (val != 0) {
        fn_803898B0((void *)val);
    }

    if (*(unsigned char *)(lbl_805A0FA8 + 0x4a5) != 0) {
        *(int *)(lbl_805A0FA8 + 0x1b4) = 0xc;
        goto tail;
    }

    m = getMode();
    if (m == 0) {
        *(int *)(lbl_805A0FA8 + 0x1b4) = 2;
        goto tail;
    }

    if (getModeP(lbl_805A0FA8) == 1) {
        *(int *)(lbl_805A0FA8 + 0x1b4) = 3;
        ret = fn_80346D80(0, 1, 0);
        if (getMode() == 0) {
            ret = fn_80349F28(ret);
        } else {
            ret = fn_80349C88();
        }
        if (ret != 0) {
            return 0;
        }
        return 1;
    }

    if (fn_803685D0(*(int *)(lbl_805A0FA8 + 0x0), *(int *)(lbl_805A0FA8 + 0x108)) != 0) {
        *(int *)(lbl_805A0FA8 + 0x1b4) = 3;
        ret = fn_80346B10(*(int *)(lbl_805A0FA8 + 0x108), 0);
        if (getMode() == 0) {
            ret = fn_80349F28(ret);
        } else {
            ret = fn_80349C88();
        }
        if (ret != 0) {
            return 0;
        }
        goto ret_one;
    }

    *(int *)(lbl_805A0FA8 + 0x1b4) = 0xd;
    fn_80342BA8(*(int *)(lbl_805A0FA8 + 0x108));

ret_one:
    return 1;

tail:
    *(int *)(lbl_805A0FA8 + 0x21c) = 0;
    ret = fn_80342BA8(*(int *)(lbl_805A0FA8 + 0x21c));
    ret = fn_80349F28(ret);
    if (ret != 0) {
        return 0;
    }
    return 1;
}
