#pragma force_active on
extern "C" void* fn_27_150488(void*, short);
extern "C" void fn_114_7BB8(void*, short);
extern "C" void* fn_27_199A54(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_7B38(void* self, short destroy) {
    short flag = -1;
    if (self != 0) {
        fn_27_150488((char*)self + 0x5B8, flag);
        fn_114_7BB8((char*)self + 0x584, flag);
        if (self != 0) {
            fn_27_199A54(self, flag);
        }
        if (destroy > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
