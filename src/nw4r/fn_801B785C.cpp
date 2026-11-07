#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_8015C238(void*, int);
void fn_801B77A0(void*, int);
}

extern "C" void* fn_801B785C(char* object, int flags) {
    if (object != 0) {
        __destroy_arr(object + 0xB4, fn_801B77A0, 0xC, 3);
        if (object + 8 != 0) {
            fn_8015C238(object + 8, 0);
        }
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
