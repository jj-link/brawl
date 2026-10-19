#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_40_1DF14(void* ptr, int size);
}

extern "C" void* fn_40_28280(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xC, fn_40_1DF14, 8, 7);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
