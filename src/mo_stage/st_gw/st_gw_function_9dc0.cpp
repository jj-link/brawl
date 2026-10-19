#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_63_9D80(void* p, int size);
}

extern "C" void* fn_63_9DC0(void* p, int size) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_63_9D80, 8, 7);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
