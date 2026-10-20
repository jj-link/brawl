#pragma force_active on
extern "C" void* fn_41_3E4D4(void*, short);
extern "C" void* fn_41_3E3E0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3E534(void* self, short shouldDelete) {
    if (self) {
        short flag = -1;
        fn_41_3E4D4(static_cast<char*>(self) + 0x2384, flag);
        fn_41_3E3E0(static_cast<char*>(self) + 4, flag);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
