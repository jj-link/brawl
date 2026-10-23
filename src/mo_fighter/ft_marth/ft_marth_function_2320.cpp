#pragma force_active on
extern "C" {
void fn_27_1A09B4(void*, short);
void __dl__FPv(void*);

void* fn_106_2320(void* self, short flag) {
    if (self != 0) {
        fn_27_1A09B4(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
