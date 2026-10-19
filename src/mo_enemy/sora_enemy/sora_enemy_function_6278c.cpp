#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62720(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_6278C(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_62CC4(static_cast<char*>(self) + 0x188, -1);
        fn_41_62720(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
