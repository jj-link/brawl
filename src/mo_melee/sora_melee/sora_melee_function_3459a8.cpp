#pragma force_active on
extern "C" {
void fn_27_1E82E8(void*, int);
void fn_27_1E847C(void*, int, void*);
void fn_27_345A24(void*);
void __register_global_object(void*, void (*)(void*), void*);
}

extern unsigned char lbl_27_bss_7EC8[];
extern unsigned char lbl_27_bss_7EBC[];
extern unsigned char lbl_27_data_8CA18[];

extern "C" void fn_27_3459A8() {
    fn_27_1E82E8(lbl_27_bss_7EC8, 0);
    unsigned char* base = lbl_27_data_8CA18;
    *(unsigned char**)(lbl_27_bss_7EC8 + 8) = base;
    *(unsigned char**)lbl_27_bss_7EC8 = base + 8;
    void* obj = lbl_27_bss_7EC8;
    fn_27_1E847C(obj, 0x45, obj);
    __register_global_object(obj, (void (*)(void*))fn_27_345A24, lbl_27_bss_7EBC);
}

__declspec(section ".ctors") extern void* const fn_27_3459A8_ctor = (void*)fn_27_3459A8;
