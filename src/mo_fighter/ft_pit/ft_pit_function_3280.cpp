#pragma force_active on
extern "C" void fn_112_32DC(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_3280(void* self, short flags) {
    if (self != 0) {
        fn_112_32DC(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
