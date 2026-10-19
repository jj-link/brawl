#pragma force_active on
extern "C" {
void fn_70_2D64(void* self, int arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_70_5DD4(void* self, int del) {
    if (self != 0) {
        fn_70_2D64(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
