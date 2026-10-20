#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_27_46B20(void* ptr, int size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_19FCBC(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))fn_27_46B20, 0xb8, 3);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
