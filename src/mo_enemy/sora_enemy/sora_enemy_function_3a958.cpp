#pragma force_active on
extern "C" void fn_41_3AAC4(void*, short);
extern "C" void fn_41_3A8EC(void*, short);

extern "C" void* fn_41_3A958(char* self, short flag) {
    if (self != 0) {
        fn_41_3AAC4(self + 0x98, -1);
        fn_41_3A8EC(self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
