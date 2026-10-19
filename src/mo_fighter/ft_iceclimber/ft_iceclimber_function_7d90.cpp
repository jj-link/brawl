#pragma force_active on
extern "C" void* fn_27_CC7EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_7D90(void* self, short flags) {
    if (self != 0) {
        fn_27_CC7EC(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
