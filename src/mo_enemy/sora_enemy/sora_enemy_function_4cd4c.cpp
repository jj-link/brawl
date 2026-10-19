#pragma force_active on
extern "C" void* fn_41_4CEB8(void* self, short destroy);
extern "C" void fn_41_4CCE0(void* self, short destroy);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4CD4C(void* self, short destroy) {
    if (self != 0) {
        fn_41_4CEB8(static_cast<char*>(self) + 0x68, -1);
        fn_41_4CCE0(static_cast<char*>(self) + 4, -1);
        if (destroy > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
