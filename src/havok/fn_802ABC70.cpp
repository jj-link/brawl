#pragma force_active on
extern "C" void fn_802AB66C(int a, int b, int c, int d);

extern "C" void fn_802ABC70(void* unused, int a, int b, int c, int d) {
    fn_802AB66C(a, b, c, d);
}
