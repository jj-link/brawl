#pragma force_active on
extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void* ptr, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_CFAD0(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0x1F);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
