#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_102_data_6E24[];
extern char lbl_102_data_6FA0[];
extern char lbl_102_data_7084[];
extern char lbl_102_data_7130[];
extern char lbl_102_data_71BC[];
extern char lbl_102_data_7248[];
extern char lbl_102_data_72D4[];
extern char lbl_102_data_7360[];
extern char lbl_102_data_73EC[];
void fn_27_1A558C(void*, int);
void fn_27_19F434(void*, int, int);
void fn_102_12AF0(void*, void*);
void fn_27_92F10(void*, void*, void*, void*, void*);
}

extern "C" void* fn_102_129A8(char* self, char* accesser) {
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    char* base = self + 0x7c;
    void* vt = lbl_102_data_6E24;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    *(void**)(self + 0x84) = lbl_102_data_7084;
    char* p = base + 0xc;
    *(void**)(self + 0x88) = lbl_102_data_7130;
    *(void**)(self + 0x8c) = lbl_102_data_71BC;
    char* q = p + 8;
    *(void**)(self + 0x90) = lbl_102_data_7248;
    *(void**)(self + 0x94) = lbl_102_data_72D4;
    char* r = q + 8;
    *(void**)(self + 0x98) = lbl_102_data_7360;
    *(void**)(self + 0x9c) = lbl_102_data_73EC;
    fn_102_12AF0(r + 0xc, accesser);
    fn_102_12AF0(r + 0x1f90, accesser);
    fn_102_12AF0(q + 0x3f1c, accesser);
    fn_102_12AF0(q + 0x5ea0, accesser);
    fn_102_12AF0(p + 0x7e2c, accesser);
    fn_102_12AF0(p + 0x9db0, accesser);
    *(void**)(base + 8) = lbl_102_data_6FA0;
    *(unsigned char*)(base + 0xbd40) = 0;
    fn_27_92F10(self + 0xbdc0, accesser, self, base, self + 0x20);
    return self;
}