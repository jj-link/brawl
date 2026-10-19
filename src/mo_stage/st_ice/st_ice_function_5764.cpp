#pragma force_active on
extern "C" {
void* fn_62_5724(void* ptr, int count);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
}

extern "C" void* fn_62_5764(void* ptr, int count) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_62_5724, 8, 7);
        if (count > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
