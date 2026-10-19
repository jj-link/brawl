#pragma force_active on
extern "C" void *fn_47_4258(void *ptr, int count);
extern "C" void __destroy_arr(void *, void (*)(void *, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void *);

extern "C" void *fn_47_4300(void *ptr, int flags)
{
    if (ptr != 0) {
        __destroy_arr((char *)ptr + 0xc, (void (*)(void *, int))fn_47_4258, 8, 6);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
