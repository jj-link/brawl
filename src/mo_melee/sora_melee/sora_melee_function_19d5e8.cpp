#pragma force_active on
extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void fn_27_4D8E0(void* buf, short value);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_19D5E8(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, (void (*)(void*, int))fn_27_4D8E0, 0x60, 2);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
