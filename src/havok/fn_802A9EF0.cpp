#pragma force_active on
extern "C" void fn_802A83F8(int, int, int, int);

extern "C" void fn_802A9EF0(void* unused, int arg1, int arg2, int arg3, int arg4) {
    fn_802A83F8(arg1, arg2, arg3, arg4);
}
