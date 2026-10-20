#pragma force_active on
extern "C" void fn_27_25290(void* ptr, int count);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_CFC68(char* self, int doDelete) {
    if (self) {
        __destroy_arr(self + 0xc, fn_27_25290, 0x30, 0x20);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
