#pragma force_active on
extern "C" void fn_802B8CC0(int, int, int, int, int);

extern "C" void fn_802B8CA8(int unused, int a, int b, int c, int d, int e) {
    fn_802B8CC0(a, b, c, d, e);
}
