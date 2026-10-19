#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_66_9950(void* ptr, int size);
void __dl__FPv(void*);
}

extern "C" void* fn_66_99F8(char* self, int flags) {
    if (self != 0) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))fn_66_9950, 8, 6);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
