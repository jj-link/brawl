#pragma force_active on
extern "C" void fn_27_1A2F18(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_110_FB28(void* self, short flags) {
    if (self != 0) {
        short m = -1;
        fn_27_1A2F18(self, m);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
