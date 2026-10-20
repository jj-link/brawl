#pragma force_active on
extern "C" {
void* fn_27_1A1FE4(void*, short);
void fn_100_55A0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_5528(char* self, short flag) {
    if (self != 0) {
        fn_27_1A1FE4(self + 0x244, -1);
        if (self != 0) {
            fn_100_55A0(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
