#pragma force_active on
extern "C" void fn_8008B334(int a, int b, int c, int d, int e, int f, int g, int h);

extern "C" void fn_8008B320(int a, int b, int c, int d, int e, int f, int g, int h) {
    fn_8008B334(a, b, c, e, 0, -1, d, h);
}
