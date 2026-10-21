#pragma force_active on
extern int lbl_80529858[0x90 / 4];

void fn_80232328(int a, int b, int c) {
    int fn = lbl_80529858[0x21];
    if (fn) {
        ((void (*)(int, int, int, int))fn)(7, a, b, c);
    }
}
