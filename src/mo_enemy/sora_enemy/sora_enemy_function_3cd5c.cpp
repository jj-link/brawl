#pragma force_active on
extern "C" void fn_41_2D244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3CD5C(void* self, int shouldDelete) {
    if (self != 0) {
        fn_41_2D244(reinterpret_cast<unsigned char*>(self) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
