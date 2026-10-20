#pragma force_active on
extern "C" {
void* fn_27_25740(void*, short);
void fn_27_2E888(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_1E311C(void* self, int flag) {
    if (self) {
        fn_27_25740((char*)self + 0x50, -1);
        if (self) {
            __destroy_arr((char*)self + 0xC, fn_27_2E888, 0x44, 1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
