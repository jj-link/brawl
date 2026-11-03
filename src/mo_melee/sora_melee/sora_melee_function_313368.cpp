#pragma force_active on

extern "C" {
void* fn_27_93100(void*, short);
void fn_27_3135A8(void*, int);
void fn_27_CDA70(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_313368(char* self, int flags) {
    if (self) {
        fn_27_93100(self + 0x1F84, -1);
        if (self + 0x40 && self + 0x40) {
            if (self + 0x48 && self + 0x48) {
                if (self + 0x4C) {
                    fn_27_3135A8(self + 0x54, -1);
                }
            }
        }
        if (self + 0x14) {
            __destroy_arr(self + 0x20, fn_27_CDA70, 0x10, 2);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
