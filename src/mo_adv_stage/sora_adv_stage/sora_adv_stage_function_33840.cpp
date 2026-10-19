#pragma force_active on
extern "C" {
void fn_27_272DD8(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_33840(void* self, int del) {
    if (self) {
        fn_27_272DD8(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
