#pragma force_active on
extern "C" void fn_41_67958(void*, short);
extern "C" void* fn_41_676B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_67714(void* self, int flag) {
    if (self) {
        short m1 = -1;
        fn_41_67958((char*)self + 0x38, m1);
        fn_41_676B4((char*)self + 4, m1);
        if ((short)flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
