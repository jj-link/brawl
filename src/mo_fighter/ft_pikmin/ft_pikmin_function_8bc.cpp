#pragma force_active on
extern "C" void fn_113_68C(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_113_8BC(void* self, short size) {
    if (self != 0) {
        fn_113_68C(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
