#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_626B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_62720(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_62CC4(self + 0x158, -1);
        fn_41_626B4(self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
