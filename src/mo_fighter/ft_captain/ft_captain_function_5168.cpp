#pragma force_active on
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void fn_100_51E0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5168(char* self, short flag) {
    if (self != 0) {
        fn_27_1A1CFC(self + 0x524, -1);
        if (self != 0) {
            fn_100_51E0(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
