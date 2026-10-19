#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62504(void*, short);

extern "C" void* fn_41_62570(void* self, short shouldDelete) {
    if (self) {
        fn_41_62CC4(static_cast<char*>(self) + 0x98, -1);
        fn_41_62504(static_cast<char*>(self) + 0x4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
