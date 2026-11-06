#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_4F20[];
extern unsigned char lbl_27_data_31F70[0x40];
void* fn_27_18F99C(void*, int);
void* __register_global_object(void*, void*, void*);

struct Obj4F2C { void* vtable; };
extern Obj4F2C lbl_27_bss_4F2C;

void fn_27_18F9DC() {
    lbl_27_bss_4F2C.vtable = 0;
    lbl_27_bss_4F2C.vtable = (void*)&lbl_27_data_31F70;
    __register_global_object(&lbl_27_bss_4F2C, (void*)fn_27_18F99C, lbl_27_bss_4F20);
}
}

__declspec(section ".ctors") extern void* const fn_27_18F9DC_ctor = (void*)fn_27_18F9DC;
