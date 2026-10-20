#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_100_5348(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_52D0(char* self, short baseDeleting) {
    if (self != 0) {
        fn_27_1A15B8(self + 0x470, -1);
        if (self != 0) {
            fn_100_5348(self, 0);
        }
        if (baseDeleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
