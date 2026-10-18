#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_60FC(void* self, int p2) {
    if (self != 0) {
        fn_27_69684(self, -1);
        if ((short)p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
