#pragma force_active on
extern "C" void fn_802A78F8(int a, int b, int c, int d, int e);

extern "C" void fn_802A9F18(void* unused, int arg1, int arg2, int arg3, int arg4, int arg5) {
    fn_802A78F8(arg1, arg2, arg3, arg4, arg5);
}
