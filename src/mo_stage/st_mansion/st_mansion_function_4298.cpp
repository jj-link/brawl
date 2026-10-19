#pragma force_active on
extern "C" {
void *fn_47_4258(void *ptr, int count);
void __destroy_arr(void *, void (*)(void *, int), unsigned long, unsigned long);
void __dl__FPv(void *);

void *fn_47_4298(void *ptr, int count)
{
    if (ptr != 0) {
        __destroy_arr((char *)ptr + 0xC, (void (*)(void *, int))fn_47_4258, 8, 7);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
