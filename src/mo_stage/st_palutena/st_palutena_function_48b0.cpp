#pragma force_active on
extern "C" {
void* fn_67_4EE0(void* ptr, int flag);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_67_48B0(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, (void (*)(void*, int))fn_67_4EE0, 0xa0, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
