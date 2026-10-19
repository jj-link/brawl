#pragma force_active on
extern "C" void fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_2AC0(void* self, short size) {
    if (self != 0) {
        fn_27_C21DC(self, -1);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
