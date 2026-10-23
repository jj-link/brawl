#pragma force_active on
extern "C" {
void fn_27_19816C(void*, short);
void __dl__FPv(void* p);

void* fn_106_2D80(void* self, short flags) {
    if (self != 0) {
        fn_27_19816C(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
