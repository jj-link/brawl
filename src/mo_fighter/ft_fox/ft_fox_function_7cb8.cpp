#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_7CB8(void* self, short deleting) {
    if (self != 0) {
        fn_27_C9EDC(self, (short)-1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
