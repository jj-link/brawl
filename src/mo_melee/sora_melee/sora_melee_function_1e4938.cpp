#pragma force_active on
extern "C" {
void* fn_27_84398(void* ptr, int size);
void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_27_1E4938(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_84398, 0xC, 4);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
