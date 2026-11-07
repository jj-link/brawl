#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_102_data_ADC[];
extern char lbl_102_data_C54[];
extern char lbl_102_data_D38[];
extern char lbl_102_data_DE0[];
extern char lbl_102_data_E68[];
extern char lbl_102_data_EF0[];
extern char lbl_102_data_F78[];
extern char lbl_102_data_1000[];
extern char lbl_102_data_1088[];

void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void fn_27_92F10(void* a, void* accesser, void* self, void* b, void* c);
void fn_102_7960(void* sub, void* accesser);
}

extern "C" void* fn_102_7818(char* self, char* accesser) {
    char* base;
    char* p;
    char* q;
    char* t;
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    base = self + 0x7c;
    void* vt = lbl_102_data_ADC;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    *(void**)(self + 0x84) = lbl_102_data_D38;
    p = base + 0xc;
    *(void**)(self + 0x88) = lbl_102_data_DE0;
    *(void**)(self + 0x8c) = lbl_102_data_E68;
    q = p + 0x8;
    *(void**)(self + 0x90) = lbl_102_data_EF0;
    *(void**)(self + 0x94) = lbl_102_data_F78;
    t = q + 0x8;
    *(void**)(self + 0x98) = lbl_102_data_1000;
    *(void**)(self + 0x9c) = lbl_102_data_1088;
    fn_102_7960(t + 0xc, accesser);
    fn_102_7960(t + 0x1f90, accesser);
    fn_102_7960(q + 0x3f1c, accesser);
    fn_102_7960(q + 0x5ea0, accesser);
    fn_102_7960(p + 0x7e2c, accesser);
    fn_102_7960(p + 0x9db0, accesser);
    *(void**)(base + 0x8) = lbl_102_data_C54;
    int zero = 0;
    *(unsigned char*)(base + 0xbd40) = zero;
    fn_27_92F10(self + 0xbdc0, accesser, self, base, self + 0x20);
    return self;
}