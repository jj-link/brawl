#pragma force_active on
extern "C" {
void fn_27_844D8(void* ptr, int size);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_DB77C(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_844D8, 0xC, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
