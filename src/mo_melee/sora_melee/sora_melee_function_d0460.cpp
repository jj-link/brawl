#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_25290(void* ptr, int count);
}

extern "C" void* fn_27_D0460(char* self, int doDelete) {
    if (self) {
        __destroy_arr(self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0x26);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
