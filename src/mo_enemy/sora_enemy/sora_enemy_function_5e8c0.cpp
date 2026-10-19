#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void* fn_41_5E860(void*, short);

extern "C" void* fn_41_5E8C0(void* self, short flag) {
    if (self) {
        fn_41_5EE64(static_cast<char*>(self) + 0x38, -1);
        fn_41_5E860(static_cast<char*>(self) + 0x4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
