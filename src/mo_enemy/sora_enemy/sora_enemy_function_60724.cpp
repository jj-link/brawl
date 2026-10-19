#pragma force_active on
extern "C" void fn_41_60968(void*, short);
extern "C" void fn_41_606B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_60724(char* self, short del) {
    if (self != 0) {
        fn_41_60968(self + 0x68, -1);
        fn_41_606B8(self + 4, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
