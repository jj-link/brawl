#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62648(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_626B4(void* self, short shouldDelete) {
    if (self) {
        fn_41_62CC4((char*)self + 0x128, -1);
        fn_41_62648((char*)self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
