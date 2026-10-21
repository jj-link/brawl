#pragma force_active on
typedef int (*Cb)(int, void*, int, int);

extern int lbl_80529858[0x90 / 4];

void fn_802322C0(void* a, int b, int c) {
    Cb f = (Cb)lbl_80529858[0x84 / 4];
    if (f == 0) {
        return;
    }
    f(5, a, b, c);
}
