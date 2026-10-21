#pragma force_active on
extern "C" void fn_802B4B1C(int a, int b, int c, int d);

extern "C" void fn_802B4B08(void* unused, int a, int b, int c, int d) {
    fn_802B4B1C(a, b, c, d);
}
