#pragma force_active on
extern "C" {
void* fn_27_13C90(void*, short);
void fn_27_137EC(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_2F822C(char* self, int flag) {
    if (self) {
        fn_27_13C90(self + 0x54, -1);
        if (self + 4 && self + 4) {
            __destroy_arr(self + 0x10, fn_27_137EC, 0x2C, 1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
