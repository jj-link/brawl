#pragma force_active on
extern "C" {

void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long n);
void __dl__FPv(void* p);
void fn_27_37D3C(void* p, int n);

void* fn_68_5CA4(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

}
