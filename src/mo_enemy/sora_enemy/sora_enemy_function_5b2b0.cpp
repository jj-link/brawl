#pragma force_active on
extern "C" void fn_41_2D244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5B2B0(void* self, int flags) {
    if (self != 0) {
        fn_41_2D244(static_cast<char*>(self) + 4, -1);
        if ((short)flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
