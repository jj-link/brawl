#pragma force_active on
extern "C" void fn_41_67958(void* self, short flag);
extern "C" void fn_41_67780(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_677EC(void* self, short flag) {
    if (self != 0) {
        fn_41_67958((char*)self + 0x98, -1);
        fn_41_67780((char*)self + 0x4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
