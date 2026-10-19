#pragma force_active on
extern "C" {
void fn_125_1B84(void* self, short arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_125_1DB4(void* self, short flags) {
    if (self != 0) {
        fn_125_1B84(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
