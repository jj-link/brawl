#pragma force_active on
extern "C" void fn_41_69BF0(void* self, short count);
extern "C" void fn_41_698D4(void* self, short count);

extern "C" void* fn_41_69940(void* self, short flag) {
    if (self != 0) {
        fn_41_69BF0((char*)self + 0x2A8, -1);
        fn_41_698D4((char*)self + 0x4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
