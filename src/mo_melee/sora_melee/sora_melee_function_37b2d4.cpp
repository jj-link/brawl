#pragma force_active on

extern "C" {
void* fn_27_13C90(void*, short);
void fn_27_22A38(void*, short);
void fn_27_86D8C(void*, int);
void fn_27_137EC(void*, int);
void fn_27_AB510(void*, int);
void fn_27_AB18C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_37B2D4(char* self, int flags) {
    if (self) {
        fn_27_13C90(self + 0x110, -1);
        if (self + 0xD4) {
            fn_27_22A38(self + 0x108, -1);
        }
        if (self + 0xA0 && self + 0xA0) {
            __destroy_arr(self + 0xAC, fn_27_86D8C, 0x14, 1);
        }
        if (self + 0x68 && self + 0x68) {
            __destroy_arr(self + 0x74, fn_27_137EC, 0x2C, 1);
        }
        if (self) {
            if (self + 0x20 && self + 0x20 && self + 0x20 && self + 0x20) {
                __destroy_arr(self + 0x2C, fn_27_AB510, 0x10, 2);
            }
            if (self) {
                __destroy_arr(self + 0xC, fn_27_AB18C, 0x14, 1);
            }
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
