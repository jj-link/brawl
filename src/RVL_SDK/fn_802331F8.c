#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);
extern int lbl_80529918[];

void fn_802331F8(unsigned char *self) {
    short *temp_r3;

    temp_r3 = (short *)fn_8022EE58(0x110);
    if (temp_r3 != 0) {
        temp_r3[0] = 0x207;
        fn_802324E0(temp_r3);
    }
    *(int *)(self + 0x108) = 0;
    ((void (*)(int, unsigned char *))lbl_80529918[0])(2, self + 8);
}
