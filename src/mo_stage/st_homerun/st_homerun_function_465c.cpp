#pragma force_active on
extern "C" {
void fn_88_43CC(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_88_465C(void* self, int flags) {
    if (self != 0) {
        fn_88_43CC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
