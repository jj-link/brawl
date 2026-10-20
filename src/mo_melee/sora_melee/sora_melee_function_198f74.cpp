#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_A6978(void*, int);

extern "C" {
void* fn_27_198F74(char* self, int flag) {
    if (self) {
        __destroy_arr(self + 0xc, fn_27_A6978, 0x24, 2);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
