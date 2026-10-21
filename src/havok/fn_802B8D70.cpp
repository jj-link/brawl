#pragma force_active on
extern "C" void fn_802B8D84(int a, int b, int c, int d);

extern "C" void fn_802B8D70(void* unused, int a, int b, int c, int d) {
    fn_802B8D84(a, b, c, d);
}
