#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62A80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_62AEC(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_62CC4(self + 0x308, -1);
        fn_41_62A80(self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
