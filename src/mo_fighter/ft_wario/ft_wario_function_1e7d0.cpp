#pragma force_active on
extern "C" {
void fn_110_1E82C(void*, short);
void __dl__FPv(void*);

void* fn_110_1E7D0(void* self, int flag) {
    if (self != 0) {
        fn_110_1E82C(self, -1);
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}
