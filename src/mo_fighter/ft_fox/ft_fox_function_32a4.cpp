#pragma force_active on
extern "C" void fn_97_3300(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_32A4(void* self, short p2) {
    if (self != 0) {
        fn_97_3300(self, -1);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
