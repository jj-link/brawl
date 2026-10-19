#pragma force_active on
extern "C" {
void fn_106_815C(void* p, short v);
void __dl__FPv(void* p);

void* fn_106_918C(void* self, short flags) {
    if (self != 0) {
        fn_106_815C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
