#pragma force_active on
extern "C" void fn_27_198524(void*, int, int);
extern "C" void fn_27_68888(void*, void*, void*, int);

extern "C" void* fn_121_3C20(void* a, void* b, int c) {
    fn_27_198524(a, 4, 0);
    fn_27_68888((char*)a + 0x7C, b, a, c);
    return a;
}
