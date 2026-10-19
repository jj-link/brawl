#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_651CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_65238(void* self, short arg2) {
    if (self != 0) {
        fn_41_65698(static_cast<char*>(self) + 0x1e8, -1);
        fn_41_651CC(static_cast<char*>(self) + 4, -1);
        if (arg2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
