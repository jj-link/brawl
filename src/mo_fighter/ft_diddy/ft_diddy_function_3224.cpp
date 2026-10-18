#pragma force_active on
extern "C" void fn_115_3280(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_3224(void* self, short p2) {
    if (self != 0) {
        fn_115_3280(self, -1);
        if (p2 > 0)
            __dl__FPv(self);
    }
    return self;
}
