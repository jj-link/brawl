#pragma force_active on
extern char lbl_80534638[];

void fn_8035DFF8(int a, int b) {
    void (*fn)(int, int) = *(void (**)(int, int))(lbl_80534638 + 8);
    fn(a, b);
}
