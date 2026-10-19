#pragma force_active on
extern "C" void fn_41_4CEB8(void*, short);
extern "C" void fn_41_4CDB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4CF18(char* self, short destroy) {
    if (self != 0) {
        fn_41_4CEB8(self + 0xC8, -1);
        fn_41_4CDB8(self + 4, -1);
        if (destroy > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
