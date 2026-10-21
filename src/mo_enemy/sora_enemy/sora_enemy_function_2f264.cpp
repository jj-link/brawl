#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_41_2F208(void*, short);
extern "C" void* fn_41_2F1AC(void*, short);
extern "C" void* fn_41_2F134(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F264(void* self, short del) {
    if (self) {
        fn_27_13C90((char*)self + 0x128, -1);
        fn_27_21038((char*)self + 0x114, -1);
        fn_41_2F208((char*)self + 0xD8, -1);
        fn_41_2F1AC((char*)self + 0x84, -1);
        fn_41_2F134(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
