#pragma force_active on
extern "C" void* fn_41_65698(void* self, short shouldDelete);
extern "C" void* fn_41_65598(void* self, short shouldDelete);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_656F8(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(self + 0x398, -1);
        fn_41_65598(self + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
