#pragma force_active on
extern "C" void fn_80032F38(int, int, int);

extern "C" void fn_80030F2C(int a) {
    fn_80032F38(a, 0, 0);
}
