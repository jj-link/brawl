#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_693C4(void*, short);

extern "C" void* fn_41_69430(void* self, short flag) {
    if (self != 0) {
        fn_41_69BF0((char*)self + 0x68, -1);
        fn_41_693C4((char*)self + 0x4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
