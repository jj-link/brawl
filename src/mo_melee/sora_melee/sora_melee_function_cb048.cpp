#pragma force_active on
typedef int s32;

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_A6978(void*, int);

void* fn_27_CB048(void* object, s32 deleting) {
    if (object) {
        __destroy_arr(static_cast<char*>(object) + 0xC, fn_27_A6978, 0x24, 9);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
