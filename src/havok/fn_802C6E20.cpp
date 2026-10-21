#pragma force_active on
extern "C" void fn_802C6E34(int a, int b, int c, int d);

extern "C" void fn_802C6E20(void* unused, int a, int b, int c, int d) {
    fn_802C6E34(a, b, c, d);
}
