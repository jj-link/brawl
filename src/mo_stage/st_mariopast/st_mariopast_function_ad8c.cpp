#pragma force_active on
extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
void* fn_27_37D3C(void* p, int n);
}

extern "C" void* fn_48_AD8C(void* p, int n)
{
    if (p != 0) {
        __destroy_arr((unsigned char*)p + 0xc, (void (*)(void*, int))fn_27_37D3C, 0x78, 0xcd);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
