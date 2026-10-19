#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void* fn_27_37D3C(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_70_8AE8(void* p, s32 flag) {
    if (p != 0) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
