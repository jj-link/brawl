#pragma force_active on
extern "C" void fn_41_5B2B0(void* self, short flags);
extern "C" void fn_41_5B1B0(void* self, short flags);

extern "C" void* fn_41_5B310(void* self, short flags) {
    if (self != 0) {
        fn_41_5B2B0((char*)self + 0xC8, -1);
        fn_41_5B1B0((char*)self + 4, -1);
        if (flags > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
