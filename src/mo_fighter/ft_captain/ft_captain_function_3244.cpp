#pragma force_active on
extern "C" void* fn_100_32B4(void*, short);
extern "C" void* fn_100_4D24(void*, short);

extern "C" void* fn_100_3244(char* self, short shouldDelete) {
    if (self != 0) {
        fn_100_32B4(self + 0x8, (short)-1);
        fn_100_4D24(self, (short)0);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
