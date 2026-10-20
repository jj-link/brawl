#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_27_84118(void* ptr, int size);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_29208C(void* ptr, int deleting) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_27_84118, 0xc, 9);
        if (deleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
