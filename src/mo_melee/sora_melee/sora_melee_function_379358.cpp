#pragma force_active on
extern "C" void fn_27_A6978(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void* fn_27_A78FC(void* p, short n);
extern "C" void* fn_27_A3704(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_379358(void* self, int flag) {
    if (self) {
        if ((char*)self + 0xD8) {
            __destroy_arr((char*)self + 0xE4, fn_27_A6978, 0x24, 1);
        }
        fn_27_A78FC((char*)self + 0x50, -1);
        fn_27_A3704((char*)self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
