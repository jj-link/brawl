#pragma force_active on
extern "C" void fn_802B8BF8(int a, int b, int c, int d);

extern "C" void fn_802B8BE4(void* unused, int a, int b, int c, int d) {
    fn_802B8BF8(a, b, c, d);
}
