#pragma force_active on
typedef unsigned short u16;

extern void *fn_8022EE58(u16 size);
extern void fn_802324E0(void *arg);

void fn_80234B88(void) {
    short *temp_r3;

    temp_r3 = (short *)fn_8022EE58(8);
    if (temp_r3 != 0) {
        *temp_r3 = 0x101;
        fn_802324E0(temp_r3);
    }
}
