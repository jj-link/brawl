#pragma force_active on
extern "C" {
void* fn_71_9E48(void* p, int flags);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_71_9318(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_71_9E48, 0xa0, 1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
