#pragma force_active on
extern "C" {
extern const char lbl_27_data_71BE0[];
extern const char lbl_27_data_CDC0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_27_29CF28(void*, char* obj) {
    char* a = *(char**)(*(char**)(obj + 0x60) + 0xD8);
    char* p = (char*)__dynamic_cast(*(void**)(a + 0x7C), 0, lbl_27_data_71BE0, lbl_27_data_CDC0, 1);
    p[0x304] = 0;
    p[0x305] = 2;
}
}
