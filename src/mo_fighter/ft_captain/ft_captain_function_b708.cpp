#pragma force_active on
extern "C" {
void* fn_100_B6A8(void* object, short shouldDelete);
void fn_100_B574(void* object, short shouldDelete);
void __dl__FPv(void* p);
}

extern "C" void* fn_100_B708(char* self, short shouldDelete) {
    if (self != 0) {
        fn_100_B6A8(self + 0x204, -1);
        if (self != 0) {
            fn_100_B574(self, 0);
        }
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
