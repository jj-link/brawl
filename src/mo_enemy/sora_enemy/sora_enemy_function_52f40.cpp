#pragma force_active on
extern "C" void fn_41_53118(void* self, short p2);
extern "C" void* fn_41_52EE0(void* ptr, short shouldDelete);

extern "C" void* fn_41_52F40(void* self, short shouldDelete) {
    short neg = -1;
    if (self != 0) {
        fn_41_53118(static_cast<char*>(self) + 0x38, neg);
        fn_41_52EE0(static_cast<char*>(self) + 0x4, neg);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
