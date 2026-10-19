#pragma force_active on
extern "C" void fn_27_1999C4(void* a, int b, int c);
extern "C" void fn_27_19BF3C(void* a, int b, int c);
extern "C" void fn_27_150320(void* a, void* b, short c, void* d, void* e);

extern "C" int fn_115_7394(int arg0, int arg1, short arg2) {
    fn_27_1999C4((void*)arg0, 10, 0);
    fn_27_19BF3C((void*)(arg0 + 0x584), 2, 0);
    fn_27_150320((void*)(arg0 + 0x5b8), (void*)arg1, arg2, (void*)arg0, (void*)(arg0 + 0x584));
    return arg0;
}
