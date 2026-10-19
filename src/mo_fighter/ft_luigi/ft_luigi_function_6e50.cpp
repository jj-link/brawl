#pragma force_active on
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void fn_27_B215C(void*, void*, void*, int, int, int);

extern "C" void* fn_99_6E50(void* object, void* arg1, int arg2, int arg3, int arg4) {
    fn_27_CB410(object, 1, 0);
    fn_27_B215C(static_cast<unsigned char*>(object) + 0x50,
                 arg1, object, arg2, arg3, arg4);
    return object;
}
