#pragma force_active on
extern "C" {
void fn_27_23EBC0(void* self, int param);
void __dl__FPv(void* ptr);

void* fn_27_241B6C(void* self, int param) {
    if (self) {
        fn_27_23EBC0(self, 0);
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
