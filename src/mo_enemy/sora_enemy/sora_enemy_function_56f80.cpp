#pragma force_active on
extern "C" void fn_41_57158(void*, short);
extern "C" void fn_41_56F14(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_56F80(char* self, short flag) {
    if (self) {
        fn_41_57158(self + 0x68, -1);
        fn_41_56F14(self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
