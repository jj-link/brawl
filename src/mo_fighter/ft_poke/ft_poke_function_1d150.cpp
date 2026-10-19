#pragma force_active on
extern "C" void* fn_27_1A5BC8(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_116_1D150(void* self, short flag) {
    if (self != 0) {
        fn_27_1A5BC8(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
