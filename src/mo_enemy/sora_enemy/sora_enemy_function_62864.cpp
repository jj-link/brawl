#pragma force_active on
extern "C" void fn_41_62CC4(void* self, short shouldDelete);
extern "C" void fn_41_627F8(void* self, short shouldDelete);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_62864(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_62CC4(static_cast<char*>(self) + 0x1E8, -1);
        fn_41_627F8(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
