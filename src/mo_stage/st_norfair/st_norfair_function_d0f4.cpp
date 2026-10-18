#pragma force_active on
extern "C" {
void fn_8009EE60(void*, int);
void fn_54_2CB0(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void __dl__FPv(void*);
extern char lbl_54_data_2E08[];
}

extern "C" void* fn_54_D0F4(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        void* tmp = *(void**)(p + 0x17c);
        *(void**)(p + 0x3c) = (void*)lbl_54_data_2E08;
        if (tmp) {
            __dl__FPv(tmp);
        }
        *(void**)(p + 0x17c) = 0;
        fn_8009EE60(p + 0x190, -1);
        __dt__14snd3DGeneratorFv(p + 0x188, -1);
        fn_54_2CB0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
