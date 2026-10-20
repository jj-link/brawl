#pragma force_active on
extern "C" {
void fn_27_46700(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CD78C(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_46700, 0x60, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
