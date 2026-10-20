#pragma force_active on
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);

extern "C" void fn_27_2655F0(void* dest, unsigned long count) {
    gfMemFill__FPvUcUl(dest, 0, count);
}
