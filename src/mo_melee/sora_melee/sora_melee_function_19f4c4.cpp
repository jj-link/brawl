#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_CDA70(void*, int);
}

extern "C" void* fn_27_19F4C4(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xC, fn_27_CDA70, 0x10, 5);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
