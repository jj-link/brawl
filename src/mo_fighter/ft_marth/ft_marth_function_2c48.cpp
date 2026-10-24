#pragma force_active on
extern "C" {
void fn_27_C21DC(void*, short);
void __dl__FPv(void* p);

void* fn_106_2C48(void* self, short flags) {
    if (self != 0) {
        fn_27_C21DC(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
