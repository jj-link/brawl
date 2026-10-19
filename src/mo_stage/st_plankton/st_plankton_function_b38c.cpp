#pragma force_active on
extern "C" {
extern void strcpy(char*, const char*);
extern void strncpy(char*, const char*, int);
extern const char lbl_74_data_2878[];
}

extern "C" void fn_74_B38C(char* buf, const char* name) {
    if (name != 0) {
        strcpy(buf + 0x158, lbl_74_data_2878);
        strncpy(buf + 0x158, name, 0x7f);
    }
}
