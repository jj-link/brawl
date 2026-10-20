#pragma force_active on
extern "C" {
void fn_27_1A18A0(void*, short);
void fn_100_53C0(void*, short);
}

extern "C" void* fn_100_5348(char* self, short flag) {
    if (self != 0) {
        fn_27_1A18A0(self + 0x354, (short)-1);
        if (self != 0) {
            fn_100_53C0(self, (short)0);
        }
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
