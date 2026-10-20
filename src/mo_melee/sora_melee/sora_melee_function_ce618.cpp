#pragma force_active on
extern "C" {
typedef unsigned long u32;
void __destroy_arr(void*, void (*)(void*, int), u32, u32);
void __dl__FPv(void*);
void* fn_27_25290(void* ptr, int count);
}

extern "C" void* fn_27_CE618(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 0x92);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
