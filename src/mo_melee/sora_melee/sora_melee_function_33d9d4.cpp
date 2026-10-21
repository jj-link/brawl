#pragma force_active on

extern "C" {
void* fn_27_13C90(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_27_AB510(void*, int);
void fn_27_AB18C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_27_33D9D4(void* self, int flag) {
    if (self) {
        fn_27_13C90((char*)self + 0x9C, -1);
        if (self) {
            if (((char*)self + 0x20) == 0) {
            } else if (((char*)self + 0x20) == 0) {
            } else if (((char*)self + 0x20) == 0) {
            } else if (((char*)self + 0x20) == 0) {
            } else {
                __destroy_arr((char*)self + 0x2C, (void (*)(void*, int))fn_27_AB510, 0x10, 4);
            }
            if (self) {
                __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
