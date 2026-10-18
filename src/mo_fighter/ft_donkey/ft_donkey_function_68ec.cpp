#pragma force_active on
extern "C" void fn_27_C96C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_68EC(void* self, short p2) {
    if (self) {
        fn_27_C96C0(self, -1);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
