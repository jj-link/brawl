#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_14814(void* self, short flags) {
    if (self != 0) {
        fn_27_5C674(self, static_cast<short>(-1));
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
