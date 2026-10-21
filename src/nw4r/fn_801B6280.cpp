#pragma force_active on
extern "C" {
extern void fn_801F2294(int, int, int, int);

void fn_801B6280(int a, int b) {
    if (b == 0) {
        return;
    }
    fn_801F2294(a + 4, b, b + 4, b + 8);
}
}
