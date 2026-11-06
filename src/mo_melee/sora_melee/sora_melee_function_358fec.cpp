#pragma force_active on

extern "C" {
extern char lbl_27_data_8F5C8[];
extern char lbl_27_bss_8098[12];
void fn_27_358FAC(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_80A4;

extern "C" void fn_27_358FEC(void) {
    lbl_27_bss_80A4.vtable = 0;
    lbl_27_bss_80A4.vtable = (void*)&lbl_27_data_8F5C8;
    __register_global_object(&lbl_27_bss_80A4, (void*)fn_27_358FAC, lbl_27_bss_8098);
}

__declspec(section ".ctors") extern void* const fn_27_358FEC_ctor = (void*)fn_27_358FEC;
