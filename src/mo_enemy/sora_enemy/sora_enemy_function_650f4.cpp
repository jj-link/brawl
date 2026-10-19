#pragma force_active on
extern "C" void fn_41_65698(void* self, short shouldDelete);
extern "C" void fn_41_65088(void* self, short shouldDelete);

extern "C" void* fn_41_650F4(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(self + 0x158, -1);
        fn_41_65088(self + 4, -1);
        if (shouldDelete > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
