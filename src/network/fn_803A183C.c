#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 lbl_80416918[];
static int leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
void fn_803A183C(u16 *arg0, u8 *arg1, u8 *arg2, s32 days) {
    s32 saved;
    *arg0 = 1900;
    *arg1 = 1;
    *arg2 = 1;
    if (days >= 0) {
        for (;;) {
            saved = days;
            days -= 365 + (leap(*arg0) != 0);
            if (days < 0) {
                days = saved;
                break;
            }
            ++*arg0;
        }
        for (;;) {
            saved = days;
            if (*arg1 == 2 && leap(*arg0)) days -= 29;
            else days -= lbl_80416918[*arg1 - 1];
            if (days < 0) break;
            ++*arg1;
        }
        *arg2 += saved;
    }
}