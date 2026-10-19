#pragma force_active on
extern "C" void fn_41_3CD5C(void*, short);
extern "C" void* fn_41_3CBFC(void*, short);

extern "C" void* fn_41_3CC5C(char* self, short flag) {
    if (self) {
        short m1 = -1;
        fn_41_3CD5C(self + 0x38, m1);
        fn_41_3CBFC(self + 4, m1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
