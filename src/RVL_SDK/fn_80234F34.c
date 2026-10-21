#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void);

void fn_80234F34(void) {
    short *temp_r3;

    temp_r3 = (short *)fn_8022EE58(8);
    if (temp_r3 != 0) {
        *temp_r3 = 0x10C;
        fn_802324E0();
    }
}
