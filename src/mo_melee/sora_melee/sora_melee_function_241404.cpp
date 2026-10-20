#pragma force_active on
extern "C" {
void fn_27_23AAC4(void* p, const char* name);
extern char lbl_27_data_4DC68[];
extern char lbl_27_data_4DC78[];
}

extern "C" void* fn_27_241404(void* p) {
    char* base = (char*)p;
    fn_27_23AAC4(p, lbl_27_data_4DC68);
    *(void**)(base + 0x3C) = lbl_27_data_4DC78;
    *(int*)(base + 0x48) = -1;
    *(int*)(base + 0x4C) = -1;
    *(int*)(base + 0x50) = 1;
    return p;
}
