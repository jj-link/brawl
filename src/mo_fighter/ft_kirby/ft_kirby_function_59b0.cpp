#pragma force_active on
extern "C" void* fn_27_1A487C(void* ptr, short shouldDelete);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_96_59B0(void* self, short flags) {
    if (self != 0) {
        fn_27_1A487C(self, (short)-1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
