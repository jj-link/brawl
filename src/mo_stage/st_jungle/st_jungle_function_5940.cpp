#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern "C" void* fn_27_37D3C(void*, s32);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_5940(void* p, s32 n)
{
    if (p != 0) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
