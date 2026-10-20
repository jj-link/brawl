#pragma force_active on

extern "C" void fn_41_35960(void*, short);
extern "C" void fn_41_3586C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_359C0(void* self, int flag) {
    if (self != 0) {
        fn_41_35960((char*)self + 0x38, -1);
        fn_41_3586C((char*)self + 4, -1);
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
