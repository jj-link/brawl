#pragma force_active on
extern "C" void fn_27_5A09C(void* ptr, int count);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_199A54(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, fn_27_5A09C, 0x8c, 10);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
