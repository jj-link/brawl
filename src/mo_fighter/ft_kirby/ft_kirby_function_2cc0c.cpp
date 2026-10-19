#pragma force_active on
extern "C" void* fn_27_1A4B88(void* ptr, short size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_96_2CC0C(void* self, short flags) {
    if (self != 0) {
        fn_27_1A4B88(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
