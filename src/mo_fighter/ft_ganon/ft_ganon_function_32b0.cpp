#pragma force_active on
extern "C" void fn_109_330C(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_109_32B0(void* self, short flag) {
    if (self != 0) {
        fn_109_330C(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
