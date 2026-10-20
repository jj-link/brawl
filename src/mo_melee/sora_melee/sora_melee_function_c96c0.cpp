#pragma force_active on
extern "C" void fn_27_137EC(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_C96C0(void* self, short p2) {
    char* p = (char*)self;
    if (self != 0) {
        __destroy_arr(p + 0xc, fn_27_137EC, 0x2c, 1);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
