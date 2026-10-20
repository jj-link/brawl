#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_27_84398(void* ptr, int size);
}

extern "C" void* fn_27_DB8E4(void* ptr, int size) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, (void (*)(void*, int))fn_27_84398, 0xC, 0x17);
        if (size > 0) {
            delete (char*)ptr;
        }
    }
    return ptr;
}
