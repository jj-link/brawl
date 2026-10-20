#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_116_1D4D4(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_1D44C(char* self, short flag) {
    if (self != 0) {
        short memberDeleting = -1;
        fn_27_93100(self + 0x923C, memberDeleting);
        fn_116_1D4D4(self + 0x7C, memberDeleting);
        fn_27_19F4C4(self + 0x20, memberDeleting);
        fn_27_1A55B0(self, memberDeleting);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
