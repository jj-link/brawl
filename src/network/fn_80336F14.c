#pragma force_active on
extern void *lbl_805A0F70;
extern void fn_8033524C(void);

void fn_80336F14(int arg0) {
    unsigned char *p;
    int type;

    if (lbl_805A0F70 == 0 || arg0 == 0) {
        return;
    }

    fn_8033524C();
    p = (unsigned char *)lbl_805A0F70;
    type = *(int *)p;

    if (type != 0 && type != 2) {
        ((void (*)(int, int, int))(*(int *)(p + 0x30)))(
            arg0, p[0x21], *(int *)(p + 0x34));
    }

    if (lbl_805A0F70 != 0) {
        *(int *)lbl_805A0F70 = 0;
        *((unsigned char *)lbl_805A0F70 + 0x22) = 0;
        *((unsigned char *)lbl_805A0F70 + 0x23) = 0;
    }
}
