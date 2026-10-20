#pragma force_active on
extern "C" void* fn_27_844D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1B1BF0(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC,
                      (void (*)(void*, int))fn_27_844D8, 0xC, 10);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
