#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void* fn_62_2CE8(void* p, int flags);
extern char lbl_62_data_1328[];
}

extern "C" void* fn_62_3680(char* self, int flags) {
    if (self) {
        void* p = *(void**)(self + 0x1b8);
        *(char**)(self + 0x3c) = lbl_62_data_1328;
        if (p) {
            __dl__FPv(p);
        }
        *(void**)(self + 0x1b8) = 0;
        __dt__14snd3DGeneratorFv(self + 0x1bc, -1);
        fn_62_2CE8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
