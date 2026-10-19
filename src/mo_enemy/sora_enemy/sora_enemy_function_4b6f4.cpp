#pragma force_active on
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void fn_41_4B688(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B6F4(char* self, short flag) {
    if (self != 0) {
        fn_41_4B7F4(self + 0x188, -1);
        fn_41_4B688(self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
