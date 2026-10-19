#pragma force_active on
extern "C" void fn_41_5B2B0(void*, short);
extern "C" void fn_41_5B144(void*, short);

extern "C" void* fn_41_5B1B0(char* self, short flags) {
    if (self != 0) {
        fn_41_5B2B0(self + 0x98, -1);
        fn_41_5B144(self + 4, -1);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
