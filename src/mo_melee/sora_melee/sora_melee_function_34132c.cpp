#pragma force_active on
extern "C" {
extern char lbl_27_bss_7E40[];
extern char lbl_27_data_8C240[];
extern char lbl_27_bss_7E34[];

void fn_27_1E82E8(void*, int);
void fn_27_1E847C(void*, int, void*);
void* fn_27_3413A8(void*, int);
void __register_global_object(void*, void* (*)(void*, int), void*);

void fn_27_34132C() {
    fn_27_1E82E8(lbl_27_bss_7E40, 0);
    *(char**)(lbl_27_bss_7E40 + 8) = lbl_27_data_8C240;
    *(char**)lbl_27_bss_7E40 = lbl_27_data_8C240 + 8;
    fn_27_1E847C(lbl_27_bss_7E40, 0x44, lbl_27_bss_7E40);
    __register_global_object(lbl_27_bss_7E40, fn_27_3413A8, lbl_27_bss_7E34);
}
}

__declspec(section ".ctors") extern void* const fn_27_34132C_ctor = (void*)fn_27_34132C;
