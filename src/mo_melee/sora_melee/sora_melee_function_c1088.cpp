#pragma force_active on
extern "C" void fn_27_C123C(void* p);

extern "C" void fn_27_C1088(void* p) {
    fn_27_C123C(p);
    fn_27_C123C((char*)p + 0x3c);
}
