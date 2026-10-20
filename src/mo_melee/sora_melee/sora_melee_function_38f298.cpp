#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_84458(void*, int);
}

extern "C" void* fn_27_38F298(void* self, int n) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xc, fn_27_84458, 0xc, 0x13);
        if (n > 0)
            __dl__FPv(self);
    }
    return self;
}
