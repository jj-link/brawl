#pragma force_active on
extern "C" void fn_41_4B544(void*, short);
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B5B0(void* self, short flag) {
    if (self) {
        fn_41_4B7F4(static_cast<char*>(self) + 0xF8, -1);
        fn_41_4B544(static_cast<char*>(self) + 0x4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
