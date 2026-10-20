#pragma force_active on

extern "C" void fn_41_65698(void*, short);
extern "C" void* fn_41_64E0C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_64E6C(void* self, int shouldDelete) {
    if (self) {
        fn_41_65698(static_cast<char*>(self) + 0x38, -1);
        fn_41_64E0C(static_cast<char*>(self) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
