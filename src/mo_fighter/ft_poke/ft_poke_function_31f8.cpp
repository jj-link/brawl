#pragma force_active on
extern "C" void fn_116_3254(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_31F8(void* self, short flags) {
    if (self != 0) {
        fn_116_3254(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
