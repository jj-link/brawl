#pragma force_active on
extern "C" {
void fn_27_4D8E0(void* buf, int value);
void __destroy_arr(void* arr, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* ptr);

void* fn_27_CD4A4(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_4D8E0, 0x60, 1);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}
