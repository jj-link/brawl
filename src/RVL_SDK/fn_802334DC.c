#pragma force_active on
typedef signed short s16;
typedef unsigned int u32;

extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);
extern int lbl_80529918[];

void fn_802334DC(u32 arg0) {
    s16 *temp_r3;

    ((void (*)(int, u32))lbl_80529918[0])(2, arg0 + 8);
    temp_r3 = (s16 *)fn_8022EE58(0x110);
    if (temp_r3 != 0) {
        *temp_r3 = 0x207;
        fn_802324E0(temp_r3);
    }
}
