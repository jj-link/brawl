#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_116_161C8(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);

extern "C" void* fn_116_16140(void* self, short flags) {
    if (self) {
        short memberDeleting = -1;
        fn_27_93100((char*)self + 0x10000 - 0x1d80, memberDeleting);
        fn_116_161C8((char*)self + 0x7c, memberDeleting);
        fn_27_19F4C4((char*)self + 0x20, memberDeleting);
        fn_27_1A55B0(self, memberDeleting);
        if (flags > 0) __dl__FPv(self);
    }
    return self;
}
