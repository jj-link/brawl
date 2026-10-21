#pragma force_active on

extern "C" {
void strcpy(char* dst, const char* src);
void strcat(char* dst, const char* src);
void fn_800B3C5C(void* model, void* info, int flag);
void fn_801AAFF0(void* model, int v);
void fn_801AB014(void* model, int v);
extern char lbl_10_data_558[];
extern char lbl_10_data_560[];
}

extern "C" void fn_10_D540(char* self, int idx, int n) {
    char buf[0x40];
    char* model = *(char**)(self + ((idx + 0xC) * 4) + 0x13C);
    char* p = *(char**)(model + 8);
    int off = *(int*)(p + 0x3C);
    char* src = off != 0 ? p + off : 0;
    strcpy(buf, src);
    strcat(buf, lbl_10_data_558);
    char* entry = lbl_10_data_560 + n * 0x14;
    *(char**)(entry + 0xC) = buf;
    fn_800B3C5C(model, entry, 0);
    fn_801AAFF0(*(void**)(model + 0xC), 0x49);
    fn_801AB014(*(void**)(model + 0xC), 0x49);
}
