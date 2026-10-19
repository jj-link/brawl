#pragma force_active on
extern "C" void fn_41_5EADC(void*, short);
extern "C" void fn_41_5EE64(void*, short);

extern "C" void* fn_41_5EB48(char* self, short doDelete) {
    if (self != 0) {
        fn_41_5EE64(self + 0x158, -1);
        fn_41_5EADC(self + 4, -1);
        if (doDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
