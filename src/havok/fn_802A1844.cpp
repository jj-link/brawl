#pragma force_active on
extern "C" void fn_802A13B4(int a, int b, int c, int d);

extern "C" void fn_802A1844(void* unused, int arg2, int arg3, int arg4, int arg5) {
    fn_802A13B4(arg2, arg3, arg4, arg5);
}
