#pragma force_active on
extern "C" void* fn_41_42944(char* p, short flag);
extern "C" void* fn_41_42720(void* self, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_429B0(char* self, short flag) {
    if (self != 0) {
        fn_41_42944(self + 0x38, -1);
        fn_41_42720(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
