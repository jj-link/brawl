#pragma force_active on
extern "C" void fn_802A1858(int a, int b, int c, int d);

extern "C" void fn_802A1D64(int unused, int a, int b, int c, int d) {
    fn_802A1858(a, b, c, d);
}
