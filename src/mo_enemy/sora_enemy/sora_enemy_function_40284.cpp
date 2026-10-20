#pragma force_active on
extern "C" void* fn_41_40224(void*, short);
extern "C" void* fn_41_40130(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_40284(void* self, short flag) {
    if (self) {
        fn_41_40224(static_cast<char*>(self) + 0x2384, -1);
        fn_41_40130(static_cast<char*>(self) + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
