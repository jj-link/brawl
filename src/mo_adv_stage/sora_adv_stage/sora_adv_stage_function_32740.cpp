#pragma force_active on
extern "C" {
void fn_40_23E68(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_32740(void* self, int n) {
    if (self) {
        fn_40_23E68(self, 0);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
