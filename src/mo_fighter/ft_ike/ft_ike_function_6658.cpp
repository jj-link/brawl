#pragma force_active on
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void fn_27_B215C(void*, void*, void*, void*, void*, void*);

extern "C" void* fn_119_6658(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4) {
    fn_27_CB410(arg0, 1, 0);
    fn_27_B215C((char*)arg0 + 0x50, arg1, arg0, arg2, arg3, arg4);
    return arg0;
}
