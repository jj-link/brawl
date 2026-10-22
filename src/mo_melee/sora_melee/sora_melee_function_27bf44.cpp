#include <types.h>
#pragma force_active on
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);
extern "C" void fn_27_27BF44(void* self, int a1, int a2, int a3, int a4) {
    char* s = (char*)self;
    gfMemFill__FPvUcUl(s + 0x188, 0, 0x2C);
    *(float*)(s + 0x1A0) = (float)a1;
    *(float*)(s + 0x1A4) = (float)a2;
    *(float*)(s + 0x1A8) = (float)a3;
    *(float*)(s + 0x1AC) = (float)a4;
    *(char**)(s + 0x1B4) = s + 0x188;
}
