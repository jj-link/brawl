#pragma force_active on
extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
void* fn_27_46B20(void* ptr, int size);

void* fn_27_19FE54(void* self, int del) {
    if (self) {
        __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_46B20, 0xB8, 4);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
