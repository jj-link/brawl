#pragma force_active on
extern "C" {
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);
void* fn_56_61AC(void* ptr, int count);
}

extern "C" void* fn_56_56A0(char* self, int flag) {
    if (self != 0) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))fn_56_61AC, 0xa0, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
