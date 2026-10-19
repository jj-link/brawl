#pragma force_active on
extern "C" {
void fn_8009EE60(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_54_2CB0(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_54_B500(void* self, int flag) {
    if (self != 0) {
        fn_8009EE60((char*)self + 0x194, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x18c, -1);
        fn_54_2CB0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
