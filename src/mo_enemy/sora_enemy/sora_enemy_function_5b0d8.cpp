#pragma force_active on
extern "C" void fn_41_5B2B0(void*, short);
extern "C" void fn_41_5B078(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5B0D8(void* self, int flags)
{
    if (self) {
        short destroy = -1;
        fn_41_5B2B0(static_cast<char*>(self) + 0x38, destroy);
        fn_41_5B078(static_cast<char*>(self) + 0x04, destroy);
        if (static_cast<short>(flags) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
