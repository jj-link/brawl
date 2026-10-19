#pragma force_active on
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void fn_41_4B61C(void*, short);

extern "C" void* fn_41_4B688(char* self, short flag) {
    if (self != 0) {
        fn_41_4B7F4(self + 0x158, -1);
        fn_41_4B61C(self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
