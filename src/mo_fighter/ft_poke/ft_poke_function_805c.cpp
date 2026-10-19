#pragma force_active on
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void fn_27_B215C(void*, void*, void*, int, int, int);

extern "C" void* fn_116_805C(void* arg0, void* arg1, int arg2, int arg3, int arg4)
{
    fn_27_CB410(arg0, 1, 0);
    fn_27_B215C(static_cast<char*>(arg0) + 0x50, arg1, arg0, arg2, arg3, arg4);
    return arg0;
}
