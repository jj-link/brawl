#pragma force_active on
extern "C" void fn_27_1A09B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_905C(void* self, short flags) {
    if (self != 0) {
        fn_27_1A09B4(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
