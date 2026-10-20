#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_1374C(void*, int);
}

extern "C" void* fn_27_198A7C(char* self, int doDelete) {
    if (self != 0) {
        __destroy_arr(self + 0xc, fn_27_1374C, 0x48, 4);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
