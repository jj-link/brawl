#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern u8 lbl_8059EA58;
void fn_801EA098(int);
void fn_801EA4E4(int, s8 *, int);

void fn_801EBBF4(void) {
    s8 buf[2];

    buf[0] = 3;
    if (lbl_8059EA58 == 1) {
        buf[1] = 0;
    } else {
        buf[1] = 1;
    }
    fn_801EA4E4(0xE0, buf, 2);
    fn_801EA098(2);
}
