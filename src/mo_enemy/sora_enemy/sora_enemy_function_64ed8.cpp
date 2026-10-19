#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_64E6C(void*, short);

extern "C" void* fn_41_64ED8(void* self, short shouldDelete) {
    if (self) {
        fn_41_65698(static_cast<char*>(self) + 0x68, -1);
        fn_41_64E6C(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
