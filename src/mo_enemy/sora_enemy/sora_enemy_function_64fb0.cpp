#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_64F44(void*, short);

extern "C" void* fn_41_64FB0(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(self + 0xC8, -1);
        fn_41_64F44(self + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
