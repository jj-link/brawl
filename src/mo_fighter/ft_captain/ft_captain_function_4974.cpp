#pragma force_active on
extern "C" void fn_100_49D4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_4974(void* self, short shouldDelete) {
    if (self != 0) {
        fn_100_49D4(static_cast<char*>(self) + 4, static_cast<short>(-1));
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
