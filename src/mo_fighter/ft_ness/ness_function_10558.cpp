#pragma force_active on
extern "C" void fn_27_16035C(void* context, int first, int second, int third);

extern "C" void fn_101_10558(void* unused, void* context, int first, int second, int third) {
    fn_27_16035C(context, first, second, third);
}
