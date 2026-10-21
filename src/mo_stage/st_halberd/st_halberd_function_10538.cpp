#pragma force_active on

extern "C" {
extern char lbl_57_data_2EB0[];
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_57_39EC(void*, int);
}

extern "C" void* fn_57_10538(void* self, int flags) {
    if (self) {
        void* p = *(void**)((char*)self + 0x178);
        *(void**)((char*)self + 0x3C) = lbl_57_data_2EB0;
        if (p) {
            __dl__FPv(p);
        }
        *(void**)((char*)self + 0x178) = 0;
        __dt__14snd3DGeneratorFv((char*)self + 0x17C, -1);
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
