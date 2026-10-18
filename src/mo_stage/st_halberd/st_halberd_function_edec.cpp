#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_8009EE60(void*, int);
void fn_57_39EC(void*, int);
extern char lbl_57_data_2C70[];
}

extern "C" void* fn_57_EDEC(char* self, int flags) {
    if (self) {
        void* p = *(void**)(self + 0x1e0);
        *(char**)(self + 0x3c) = lbl_57_data_2C70;
        if (p) {
            __dl__FPv(p);
        }
        *(void**)(self + 0x1e0) = 0;
        __dt__14snd3DGeneratorFv(self + 0x268, -1);
        fn_8009EE60(self + 0x1e4, -1);
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
