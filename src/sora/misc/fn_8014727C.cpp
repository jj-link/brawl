#pragma force_active on
struct StrTable {
    const char* p[15];
};

extern "C" {
extern StrTable lbl_8045F738;
extern unsigned char lbl_8045F50C[0x40];
}

extern "C" const char* fn_8014727C(int unused, int index) {
    StrTable table = lbl_8045F738;
    if (index < 0 || index >= 15) {
        return (const char*)lbl_8045F50C;
    }
    return table.p[index];
}
