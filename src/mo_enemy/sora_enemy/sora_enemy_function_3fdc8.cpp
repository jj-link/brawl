#pragma force_active on
extern "C" void fn_41_3FFA0(void*, short);
extern "C" void fn_41_3FD5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3FDC8(void* self, short flag) {
    if (self != 0) {
        fn_41_3FFA0((char*)self + 0x68, -1);
        fn_41_3FD5C((char*)self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
