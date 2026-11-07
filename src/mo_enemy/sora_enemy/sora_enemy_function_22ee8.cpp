#pragma force_active on
extern "C" {
extern char lbl_27_bss_A48[];
extern char lbl_41_data_32D0[];
void fn_27_A34D4(void* a1, void* a2, unsigned char a3, void* a4, void* a5, void* a6, void* a7, void* a8, int a9);
void fn_27_CB5A8(void* p, int x);
void fn_27_A78C0(void* self);
}

extern "C" void* fn_41_22EE8(char* self, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7) {
    fn_27_A34D4(self, arg1, 1, arg5, self + 0x60, self + 0x48C, arg7, lbl_27_bss_A48, -1);
    *(char**)(self + 0x00) = lbl_41_data_32D0;
    *(char**)(self + 0x08) = lbl_41_data_32D0 + 0x88;
    *(char**)(self + 0x0C) = lbl_41_data_32D0 + 0x94;
    *(char**)(self + 0x18) = lbl_41_data_32D0 + 0xA8;
    *(char**)(self + 0x24) = lbl_41_data_32D0 + 0xB8;
    *(void**)(self + 0x4C) = arg1;
    *(void**)(self + 0x50) = arg3;
    fn_27_CB5A8(self + 0x60, 0);
    fn_27_A78C0(self + 0x48C);
    char* p = self + 0x4A8;
    do {
        p += 0xC;
    } while (p < self + 0x568);
    *(void**)(self + 0x58) = arg2;
    *(void**)(self + 0x54) = arg6;
    *(void**)(self + 0x5C) = arg4;
    return self;
}
