#pragma force_active on
extern "C" void fn_41_49F40(void* self, short p2);
extern "C" void fn_41_49DE0(void* ptr, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_49E40(void* self, short flag) {
    if (self != 0) {
        short neg = -1;
        fn_41_49F40((char*)self + 0x38, neg);
        fn_41_49DE0((char*)self + 4, neg);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
