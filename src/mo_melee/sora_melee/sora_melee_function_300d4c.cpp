#pragma force_active on
extern "C" {
void fn_27_300DC8(void* p, short v);
void fn_27_300E8C(void* p, short v);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_300D4C(char* self, int flag) {
    if (self) {
        if (self + 0xcc) {
            fn_27_300DC8(self + 0x182c, -1);
            fn_27_300E8C(self + 0xcc, 0);
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
