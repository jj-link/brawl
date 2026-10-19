#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_650F4(void*, short);

extern "C" void* fn_41_65160(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(static_cast<char*>(self) + 0x188, -1);
        fn_41_650F4(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
