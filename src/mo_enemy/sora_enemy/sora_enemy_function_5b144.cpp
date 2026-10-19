#pragma force_active on
extern "C" void* fn_41_5B2B0(void* self, short flags);
extern "C" void fn_41_5B0D8(void* self, short flags);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5B144(void* self, short flags) {
    short s = -1;
    if (self) {
        char* p = (char*)self;
        fn_41_5B2B0(p + 0x68, s);
        fn_41_5B0D8(p + 0x4, s);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
