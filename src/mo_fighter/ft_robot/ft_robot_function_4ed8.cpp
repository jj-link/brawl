#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_4ED8(void* self, short flags) {
    if (self != 0) {
        fn_27_64D9C(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
