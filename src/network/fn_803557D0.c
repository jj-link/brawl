#pragma force_active on
extern void *lbl_805A0FE8;
extern void OSJoinThread(void *thread, void *val);
extern void fn_80335450(int type, void *p, int flag);

void fn_803557D0(void) {
    void (*temp_r31)(void);

    OSJoinThread((char *)lbl_805A0FE8 + 0x51C0, 0);
    temp_r31 = *(void (**)(void))((char *)lbl_805A0FE8 + 4);
    fn_80335450(0xA, lbl_805A0FE8, 0);
    lbl_805A0FE8 = 0;
    if (temp_r31 != 0) {
        temp_r31();
    }
}
