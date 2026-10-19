#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5C14(void* self, short param2) {
    if (self != 0) {
        fn_27_C9EDC(self, (short)-1);
        if (param2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
