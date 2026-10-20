#pragma force_active on
extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
void* fn_27_8D588(void* p, int n);
}

extern "C" void* fn_27_1D5500(void* p, int flag) {
    if (p) {
        if (p) {
            __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_8D588, 0xC, 9);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
