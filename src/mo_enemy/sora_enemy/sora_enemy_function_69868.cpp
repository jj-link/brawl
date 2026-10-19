#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_697FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69868(char* self, short flag) {
    if (self != 0) {
        fn_41_69BF0(self + 0x248, -1);
        fn_41_697FC(self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
