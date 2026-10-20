#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_CDA70(void* p, int flags);
}

extern "C" void* fn_27_19F194(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_CDA70, 0x10, 0x19);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
