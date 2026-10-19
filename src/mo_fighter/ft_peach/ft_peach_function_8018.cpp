#pragma force_active on
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void fn_27_B215C(void*, void*, void*, void*, void*, void*);

extern "C" void* fn_103_8018(void* a, void* b, void* c, void* d, void* e) {
    fn_27_CB410(a, 1, 0);
    fn_27_B215C(static_cast<unsigned char*>(a) + 0x50, b, a, c, d, e);
    return a;
}
