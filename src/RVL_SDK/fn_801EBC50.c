#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern void fn_801EA098(int);
extern void fn_801EA4E4(int, u8 *, int);
extern s32 lbl_805A085C;
extern s32 lbl_805A0868;

void fn_801EBC50(void) {
    u8 buf[2];

    if (lbl_805A0868 == 3) {
        buf[0] = 10;
        buf[1] = (lbl_805A085C << 1) | 1;
        fn_801EA4E4(0xE0, buf, 2);
        fn_801EA098(2);
        return;
    }
    buf[0] = 10;
    buf[1] = 0;
    fn_801EA4E4(0xE0, buf, 2);
    fn_801EA098(2);
}
