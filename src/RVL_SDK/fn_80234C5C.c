#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_8022EE58(u16 size);
extern void fn_802324E0(void *arg);

void fn_80234C5C(u8 arg0, u8 arg1) {
    short *temp_r3;

    temp_r3 = (short *)fn_8022EE58(0x110);
    if (temp_r3 != 0) {
        *temp_r3 = 0x103;
        *((u8 *)temp_r3 + 8) = arg0;
        *((u8 *)temp_r3 + 9) = arg1;
        fn_802324E0(temp_r3);
    }
}
