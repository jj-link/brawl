#pragma force_active on
extern "C" void fn_27_2726B4(void* self, int arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_40_31200(void* self, int flag) {
    if (self) {
        fn_27_2726B4(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
