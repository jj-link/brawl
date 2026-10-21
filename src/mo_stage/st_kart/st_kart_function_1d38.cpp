#pragma force_active on
extern "C" {
extern char lbl_49_data_1100[];
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_49_1414(void* p, int del);
void __dl__FPv(void* p);
}

extern "C" void* fn_49_1D38(char* self, int del) {
    if (self != 0) {
        int idx = *(int*)(self + 0xc0);
        *(char**)(self + 0x3c) = lbl_49_data_1100;
        void* item = *(void**)(*(char**)(self + 0x44) + idx * 4);
        if (item != 0) {
            *(int*)((char*)item + 0xd4) = 0;
        }
        __dt__14snd3DGeneratorFv(self + 0x26c, -1);
        fn_49_1414(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
