#pragma force_active on
extern "C" void fn_802B9BA0(int a, int b, int c, int d);

extern "C" void fn_802B9B8C(int unused, int a, int b, int c, int d) {
    fn_802B9BA0(a, b, c, d);
}
