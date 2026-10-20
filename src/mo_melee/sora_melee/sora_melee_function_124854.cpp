#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
void* fn_27_124990(void* p, int n);
}

extern "C" void* fn_27_124854(u8* self, int n) {
    if (self) {
        if (self) {
            __destroy_arr(self + 0xC, (void (*)(void*, int))fn_27_124990, 0x18, 0x10);
        }
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
