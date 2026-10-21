#pragma force_active on
extern int lbl_804F6810[];

void fn_8021C97C(int arg0) {
    unsigned char *p = (unsigned char *)lbl_804F6810[arg0];
    p[0x8CB] = p[0x8CC];
    *(int *)(p + 0x838) = (p[0x8CC] != 0);
}
