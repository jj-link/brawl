#pragma force_active on
extern "C" {
void* fn_100_B1E8(void*, short);
void fn_100_B0B4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_B248(void* self, short del) {
    if (self != 0) {
        fn_100_B1E8((char*)self + 0x134, -1);
        if (self != 0) {
            fn_100_B0B4(self, 0);
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
