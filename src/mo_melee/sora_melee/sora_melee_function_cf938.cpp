#pragma force_active on
typedef unsigned long u32;

extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), u32 size, u32 count);
extern "C" void* fn_27_25290(void* ptr, int count);

extern "C" void* fn_27_CF938(char* p, int flag) {
    if (p) {
        __destroy_arr(p + 0xc, (void (*)(void*, int))fn_27_25290, 0x30, 3);
        if (flag > 0) {
            delete p;
        }
    }
    return p;
}
