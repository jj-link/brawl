#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_84398(void*, int);
}

extern "C" void* fn_27_29215C(void* object, int deleting) {
    if (object) {
        __destroy_arr((void*)((u8*)object + 0xc), fn_27_84398, 0xc, 0x14);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
