#pragma force_active on
extern "C" {
void fn_27_2726B4(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_40_27868(void* self, int del) {
    if (self) {
        fn_27_2726B4(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
