#pragma force_active on
#pragma optimization_level 1
extern "C" {
void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void fn_116_8BD0(void* p, int arg);
void fn_116_8C64(void* p, int arg);
void fn_116_8CF8(void* p, int arg);
void fn_27_92F10(void* p, int arg, void* a, void* b, void* c);
extern char lbl_116_data_B24[];
extern char lbl_116_data_19FC[];
extern char lbl_116_data_1AB0[];
extern char lbl_116_data_1B44[];
extern char lbl_116_data_1BD8[];
extern char lbl_116_data_1C6C[];
extern char lbl_116_data_1628[];
extern char lbl_116_data_1798[];
extern char lbl_116_data_1828[];
extern char lbl_116_data_FD0[];
extern char lbl_116_data_11A8[];
extern char lbl_116_data_1238[];
extern char lbl_116_data_12C8[];
extern char lbl_116_data_1358[];
extern char lbl_116_data_13E8[];
extern char lbl_116_data_E10[];
}

extern "C" void* fn_116_89F4(char* self, int arg1) {
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    char* p7c = self + 0x7C;
    char* vt = lbl_116_data_B24;
    *(void**)p7c = vt;
    *(void**)(p7c + 4) = vt + 0x10;
    char* p84 = p7c + 8;
    *(void**)p84 = lbl_116_data_19FC;
    *(void**)(p84 + 4) = lbl_116_data_1AB0;
    char* p8c = p84 + 8;
    *(void**)p8c = lbl_116_data_1B44;
    *(void**)(p8c + 4) = lbl_116_data_1BD8;
    *(void**)(p8c + 8) = lbl_116_data_1C6C;
    fn_116_8BD0(p8c + 0x10, arg1);
    fn_116_8BD0(p8c + 0x16F0, arg1);
    fn_116_8BD0(p8c + 0x2DD0, arg1);
    fn_116_8BD0(p84 + 0x44B8, arg1);
    *(void**)p84 = lbl_116_data_1628;
    *(void**)(p84 + 0x5B98) = lbl_116_data_1798;
    *(void**)(p84 + 0x5B9C) = lbl_116_data_1828;
    fn_116_8C64(p84 + 0x5BA4, arg1);
    fn_116_8C64(p84 + 0x7494, arg1);
    *(void**)p84 = lbl_116_data_FD0;
    char* p8d = p84 + 0x10000;
    *(void**)(p8d - 0x727C) = lbl_116_data_11A8;
    char* p26;
    char* p25 = p8d - 0x7278;
    *(void**)p25 = lbl_116_data_1238;
    *(void**)(p25 + 4) = lbl_116_data_12C8;
    p26 = p25 + 8;
    *(void**)p26 = lbl_116_data_1358;
    *(void**)(p26 + 4) = lbl_116_data_13E8;
    fn_116_8CF8(p26 + 0xC, arg1);
    fn_116_8CF8(p26 + 0x165C, arg1);
    fn_116_8CF8(p25 + 0x2CB4, arg1);
    fn_116_8CF8(p25 + 0x4304, arg1);
    fn_116_8CF8(p8d - 0x1924, arg1);
    *(void**)p84 = lbl_116_data_E10;
    *(char*)(p7c + 0xFD34) = 0;
    fn_27_92F10(self + 0xFDB4, arg1, self, p7c, self + 0x20);
    return self;
}
