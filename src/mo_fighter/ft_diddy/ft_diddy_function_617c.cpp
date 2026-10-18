#pragma force_active on
extern "C" void fn_27_C96C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_617C(void* self, short destroy) {
    if (self != 0) {
        fn_27_C96C0(self, -1);
        if (destroy > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
