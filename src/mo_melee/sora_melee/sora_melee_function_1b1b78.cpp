#pragma force_active on
extern "C" {
void* fn_27_84118(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_1B1B78(void* ptr, int flag) {
    if (ptr) {
        __destroy_arr((char*)ptr + 0xC,
                      (void (*)(void*, int))fn_27_84118, 0xC, 8);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
