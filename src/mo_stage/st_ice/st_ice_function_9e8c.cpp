#pragma force_active on
extern "C" {
void* fn_62_A404(void* ptr, int deleteFlag);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
}

void operator delete(void* p);

extern "C" void* fn_62_9E8C(void* ptr, int deleteFlag) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, (void (*)(void*, int))fn_62_A404, 0xa0, 1);
        if (deleteFlag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
