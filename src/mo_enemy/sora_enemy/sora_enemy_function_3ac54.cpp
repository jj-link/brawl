#pragma force_active on
extern "C" void* fn_41_3ABF0(void* self, short shouldDelete);
extern "C" void* fn_41_33D4C(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_3AC54(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_3ABF0((char*)self + 8, -1);
        fn_41_33D4C(self, 0);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
