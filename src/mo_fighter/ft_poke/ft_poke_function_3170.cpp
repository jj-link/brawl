#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_116_31F8(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_3170(char* self, short flags) {
    if (self) {
        short memberDeleting = -1;
        fn_27_93100(self + 0xFDB4, memberDeleting);
        fn_116_31F8(self + 0x7C, memberDeleting);
        fn_27_19F4C4(self + 0x20, memberDeleting);
        fn_27_1A55B0(self, memberDeleting);
        if (flags > 0) __dl__FPv(self);
    }
    return self;
}
