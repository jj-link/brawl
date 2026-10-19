#pragma force_active on
extern "C" void fn_41_556F4(void*, short);
extern "C" void* fn_41_554BC(void* ptr, short deleting);

extern "C" void* fn_41_5551C(void* self, short deleting) {
    if (self) {
        short m1 = -1;
        fn_41_556F4((char*)self + 0x38, m1);
        fn_41_554BC((char*)self + 4, m1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
