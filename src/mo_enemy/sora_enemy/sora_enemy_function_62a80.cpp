#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62A14(void*, short);

extern "C" void* fn_41_62A80(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_62CC4(static_cast<char*>(self) + 0x2D8, -1);
        fn_41_62A14(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
