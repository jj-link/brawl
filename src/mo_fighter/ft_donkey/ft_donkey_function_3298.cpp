#pragma force_active on
extern "C" void fn_92_32F4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3298(void* self, short flag) {
    if (self != 0) {
        fn_92_32F4(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
