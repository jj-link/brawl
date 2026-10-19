#pragma force_active on
extern "C" void* fn_112_1E8C(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_1E30(void* self, short flag) {
    if (self != 0) {
        fn_112_1E8C(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
