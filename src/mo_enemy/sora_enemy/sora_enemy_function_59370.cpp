#pragma force_active on
extern "C" void fn_41_59310(void*, short);
extern "C" void fn_41_5921C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_59370(void* self, short flag) {
    if (self != 0) {
        fn_41_59310(static_cast<char*>(self) + 0x2384, -1);
        fn_41_5921C(static_cast<char*>(self) + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
