#pragma force_active on
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void fn_41_4B400(void*, short);

extern "C" void* fn_41_4B46C(void* self, short flag) {
    if (self) {
        fn_41_4B7F4(static_cast<char*>(self) + 0x68, -1);
        fn_41_4B400(static_cast<char*>(self) + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
