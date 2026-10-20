#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
void* fn_57_39EC(void* p, int del);
char lbl_57_data_1CF0[];
}

extern "C" void* fn_57_89C4(char* self, int flags) {
    if (self) {
        void* p = *(void**)(self + 0x178);
        *(void**)(self + 0x3c) = &lbl_57_data_1CF0;
        if (p) {
            __dl__FPv(p);
        }
        *(void**)(self + 0x178) = 0;
        fn_57_39EC(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
