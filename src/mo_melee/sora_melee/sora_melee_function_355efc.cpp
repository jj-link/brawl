#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 a, b, c, d;
};

extern "C" {
void fn_27_1E82E8(void*, int);
void fn_27_1E847C(void*, int, void*);
void __register_global_object(void*, void (*)(), void*);
void fn_27_355F78();
}

extern unsigned char lbl_27_data_8F0C0[];
extern Obj lbl_27_bss_7FE8;
extern unsigned char lbl_27_bss_7FDC[];

extern "C" void fn_27_355EFC() {
    fn_27_1E82E8(&lbl_27_bss_7FE8, 0);
    ((u32*)&lbl_27_bss_7FE8)[2] = (u32)lbl_27_data_8F0C0;
    ((u32*)&lbl_27_bss_7FE8)[0] = (u32)(lbl_27_data_8F0C0 + 8);
    fn_27_1E847C(&lbl_27_bss_7FE8, 0x24, &lbl_27_bss_7FE8);
    __register_global_object(&lbl_27_bss_7FE8, fn_27_355F78, lbl_27_bss_7FDC);
}

__declspec(section ".ctors") extern void* const fn_27_355EFC_ctor = (void*)fn_27_355EFC;
