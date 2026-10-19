#pragma force_active on
extern "C" {
void fn_52_363C(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_52_114F4(void* self, int flags) {
    if (self != 0) {
        fn_52_363C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
