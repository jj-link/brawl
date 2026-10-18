#pragma force_active on
extern "C" void fn_41_3056C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_35BE4(void* self, short flags) {
    if (self != 0) {
        fn_41_3056C(static_cast<unsigned char*>(self) + 4, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
