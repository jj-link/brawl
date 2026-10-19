#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_64FB0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_6501C(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(self + 0xF8, -1);
        fn_41_64FB0(self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
