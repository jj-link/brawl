#pragma force_active on
extern "C" {
void fn_27_1540CC(void* p, short v);
void __dl__FPv(void* p);

void* fn_106_45B0(void* self, short flags) {
    if (self != 0) {
        fn_27_1540CC(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
