#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_A6978(void*, int);
}

extern "C" void* fn_27_CA210(char* self, int doDelete) {
    if (self) {
        __destroy_arr(self + 0xc, fn_27_A6978, 0x24, 10);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
