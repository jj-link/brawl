#pragma force_active on
extern "C" void fn_802C3758(int arg1, int arg2, int arg3, int arg4);

extern "C" void fn_802C3A54(void* unused, int arg1, int arg2, int arg3, int arg4) {
    fn_802C3758(arg1, arg2, arg3, arg4);
}
