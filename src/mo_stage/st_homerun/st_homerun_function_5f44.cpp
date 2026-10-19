#pragma force_active on
extern "C" {
void fn_88_4D64(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_88_5F44(void* self, int flags) {
    if (self) {
        fn_88_4D64(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
