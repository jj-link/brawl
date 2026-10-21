#pragma force_active on
extern "C" {
extern void fn_802E7554(int, int, int, int, int);

void fn_802DF6E4(int a, int b, int c, int d) {
    fn_802E7554(a, d + 0x80, b, c, 0xA0);
}
}
