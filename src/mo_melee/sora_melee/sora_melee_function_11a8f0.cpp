#pragma force_active on
extern "C" {
void* fn_27_11AD84(void* p, int flags);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);

void* fn_27_11A8F0(char* p, int flags) {
    if (p) {
        __destroy_arr(p + 0xC, (void (*)(void*, int))fn_27_11AD84, 0xC, 4);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
