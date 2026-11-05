#pragma force_active on
extern int lbl_80529858[0x90 / 4];

void fn_802321FC(int a, int b, int c) {
    if (lbl_80529858[0x80 / 4] != 0)
        ((void (*)(int, int, int, int))lbl_80529858[0x80 / 4])(1, a, b, c);
    if (lbl_80529858[0x84 / 4] != 0)
        ((void (*)(int, int, int, int))lbl_80529858[0x84 / 4])(1, a, b, c);
    if (lbl_80529858[0x88 / 4] != 0)
        ((void (*)(int, int, int, int))lbl_80529858[0x88 / 4])(1, a, b, c);
}