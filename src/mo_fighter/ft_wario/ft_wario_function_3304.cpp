#pragma force_active on
extern "C" void fn_110_3360(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_3304(void* self, int flag) {
    if (self != 0) {
        fn_110_3360(self, -1);
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
