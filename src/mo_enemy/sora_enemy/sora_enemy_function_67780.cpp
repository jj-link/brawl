#pragma force_active on
extern "C" void fn_41_67958(void* self, short flag);
extern "C" void fn_41_67714(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_67780(void* self, short flag) {
    if (self) {
        short m1 = -1;
        fn_41_67958((char*)self + 0x68, m1);
        fn_41_67714((char*)self + 4, m1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
