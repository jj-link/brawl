#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_4184(void* self, short count) {
    if (self != 0) {
        fn_27_69684(self, -1);
        if (count > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
