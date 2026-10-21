#pragma force_active on
extern "C" void fn_802B5B50(int a, int b, int c, int d, int e);

extern "C" void fn_802B60A0(void* unused, int arg2, int arg3, int arg4, int arg5, int arg6) {
    fn_802B5B50(arg2, arg3, arg4, arg5, arg6);
}
