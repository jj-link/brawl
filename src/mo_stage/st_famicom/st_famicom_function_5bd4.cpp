#pragma force_active on
extern "C" {
void* fn_68_6204(void* ptr, int size);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_68_5BD4(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_68_6204, 0xa0, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
