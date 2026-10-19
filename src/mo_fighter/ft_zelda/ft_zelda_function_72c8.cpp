#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_72C8(void* self, short p2) {
    if (self) {
        fn_27_1A75E4(self, -1);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
