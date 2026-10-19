#pragma force_active on
extern "C" void fn_41_3FFA0(void*, short);
extern "C" void fn_41_3FE34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3FEA0(void* self, short flags) {
    if (self) {
        fn_41_3FFA0((char*)self + 0xC8, -1);
        fn_41_3FE34((char*)self + 4, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
