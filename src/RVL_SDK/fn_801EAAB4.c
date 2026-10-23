#pragma force_active on
extern void fn_801EA098(int);
extern void fn_801EA4E4(int, unsigned char *, int);
extern int lbl_805A0868;

void fn_801EAAB4(int arg0) {
    unsigned char buf[2];
    int temp_r0;

    temp_r0 = *(int *)0x800000CC;
    switch (temp_r0) {
    case 5:
    case 1:
        lbl_805A0868 = 2;
        break;
    case 2:
        lbl_805A0868 = 1;
        break;
    case 0:
        lbl_805A0868 = 0;
        break;
    default:
        lbl_805A0868 = 0;
        break;
    }
    buf[0] = 1;
    buf[1] = ((arg0 << 5) & 0x1FE0) | lbl_805A0868;
    fn_801EA4E4(0xE0, buf, 2);
    fn_801EA098(2);
}
