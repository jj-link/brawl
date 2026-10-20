#pragma force_active on
extern "C" void fn_41_57158(void*, short);
extern "C" void* fn_41_56EB4(void* object, short shouldDelete);

extern "C" void* fn_41_56F14(void* self, short shouldDelete) {
    short neg = -1;
    if (self != 0) {
        fn_41_57158(static_cast<char*>(self) + 0x38, neg);
        fn_41_56EB4(static_cast<char*>(self) + 4, neg);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
