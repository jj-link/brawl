#pragma force_active on
extern "C" {
void fn_106_1AFC(void*, short);
void __dl__FPv(void* p);

void* fn_106_1BBC(void* self, short flags) {
    if (self != 0) {
        fn_106_1AFC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
