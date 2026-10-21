#pragma force_active on
extern "C" {
extern void fn_80281D64(int a, int b, int c);

void fn_802DE240(int a, int b, int c, int d) {
    if (c == 0) {
        return;
    }
    fn_80281D64(c, 0, d);
}
}
