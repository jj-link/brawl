#pragma force_active on
extern "C" void fn_20_2D50(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_20_3024(void* self, int size) {
    if (self != 0) {
        fn_20_2D50(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
