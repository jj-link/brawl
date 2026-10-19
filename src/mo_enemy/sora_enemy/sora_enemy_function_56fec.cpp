#pragma force_active on
extern "C" void fn_41_57158(void*, short);
extern "C" void fn_41_56F80(void*, short);

extern "C" void* fn_41_56FEC(char* self, short del) {
    if (self != 0) {
        fn_41_57158(self + 0x98, -1);
        fn_41_56F80(self + 4, -1);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
