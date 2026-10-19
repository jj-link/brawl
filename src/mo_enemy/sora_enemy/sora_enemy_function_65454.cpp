#pragma force_active on
extern "C" void fn_41_65698(void* self, short shouldDelete);
extern "C" void fn_41_653E8(void* self, short shouldDelete);

extern "C" void* fn_41_65454(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(static_cast<char*>(self) + 0x2d8, -1);
        fn_41_653E8(static_cast<char*>(self) + 0x4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
