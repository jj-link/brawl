#pragma force_active on

extern "C" void fn_41_40284(void*, short);
extern "C" void* fn_41_400CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_402F0(void* self, short flag) {
    if (self != 0) {
        fn_41_40284(static_cast<char*>(self) + 0x128, -1);
        fn_41_400CC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
