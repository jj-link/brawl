#pragma force_active on
extern "C" void fn_41_4CEB8(void*, short);
extern "C" void* fn_41_4CC80(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4CCE0(void* self, short del) {
    if (self) {
        short flag = -1;
        fn_41_4CEB8((char*)self + 0x38, flag);
        fn_41_4CC80((char*)self + 4, flag);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
