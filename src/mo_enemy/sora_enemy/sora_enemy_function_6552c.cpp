#pragma force_active on

extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_654C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_6552C(void* self, short release) {
    if (self != 0) {
        fn_41_65698(static_cast<char*>(self) + 0x338, -1);
        fn_41_654C0(static_cast<char*>(self) + 4, -1);
        if (release > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
