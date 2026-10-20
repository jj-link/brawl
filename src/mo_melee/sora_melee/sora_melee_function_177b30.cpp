#pragma force_active on
extern "C" void fn_27_176ED4(void*, void*, float, float);
extern "C" void fn_27_176C68(void*, void*, float, int);
extern "C" void fn_27_176D6C(void*, void*, float, float, int);

extern "C" void fn_27_177B30(void* a, void* b, float* c) {
    fn_27_176ED4(a, b, c[2], c[3]);
    fn_27_176C68(a, b, c[2], 1);
    fn_27_176D6C(a, b, c[3], c[6], 1);
}
