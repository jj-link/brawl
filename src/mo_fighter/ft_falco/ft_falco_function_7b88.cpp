#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_7B88(void* self, int p2) {
    if (self != 0) {
        fn_27_C9EDC(self, (short)-1);
        if ((short)p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
