#pragma force_active on
extern "C" void fn_41_60968(void* self, short destroy);
extern "C" void fn_41_60868(void* self, short destroy);

extern "C" void* fn_41_609C8(char* self, short destroy) {
    if (self != 0) {
        fn_41_60968(self + 0x128, -1);
        fn_41_60868(self + 4, -1);
        if (destroy > 0) {
            operator delete(self);
        }
    }
    return self;
}
