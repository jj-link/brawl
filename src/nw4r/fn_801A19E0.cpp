#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_8000CEE8(void*, int);
}

extern "C" void* fn_801A19E0(char* object, int flags) {
    if (object != 0) {
        __destroy_arr(object + 0x2c, fn_8000CEE8, 0x44, 0x80);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}