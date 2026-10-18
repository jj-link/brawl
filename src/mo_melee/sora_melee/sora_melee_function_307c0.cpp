#pragma force_active on
extern "C" void fn_27_2FEB4(void* obj, int a, int b);
extern "C" void fn_27_2EFD4(void* obj);

extern "C" void fn_27_307C0(int unused, void* obj, int a, int b) {
    fn_27_2FEB4(obj, a, b);
    fn_27_2EFD4(obj);
}
