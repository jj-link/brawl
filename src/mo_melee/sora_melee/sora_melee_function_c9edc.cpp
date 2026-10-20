#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_1374C(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_C9EDC(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xc, fn_27_1374C, 0x48, 2);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
