#pragma force_active on
extern "C" void fn_27_4E038(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_CD4A4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_41_2F654(void* self, short deleteFlag) {
    if (self != 0) {
        fn_27_4E038((char*)self + 0xF0, -1);
        fn_27_4CAA0((char*)self + 0x6C, -1);
        fn_27_CD4A4(self, -1);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
