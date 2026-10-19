#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_48_3E50(void* ptr, int size);
}

extern "C" void* fn_48_AE8C(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))fn_48_3E50, 0xa0, 0x3a);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
