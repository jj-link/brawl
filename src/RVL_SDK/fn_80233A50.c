#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);

void fn_80233A50(short arg0) {
    short *temp_r3;

    temp_r3 = (short *)fn_8022EE58(10);
    if (temp_r3 != 0) {
        temp_r3[0] = 0x206;
        temp_r3[4] = arg0;
        fn_802324E0(temp_r3);
    }
}
