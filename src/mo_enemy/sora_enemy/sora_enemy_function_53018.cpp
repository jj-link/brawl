#pragma force_active on
extern "C" void fn_41_53118(void* self, short p2);
extern "C" void fn_41_52FAC(void* self, short p2);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_53018(char* self, short flag) {
    if (self != 0) {
        fn_41_53118(self + 0x98, -1);
        fn_41_52FAC(self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
