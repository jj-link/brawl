#pragma force_active on

extern "C" {
extern char lbl_27_data_85D30[];
extern char lbl_27_bss_7BE0[0xC];
void* fn_27_31EE84(void*, int);
void* __register_global_object(void*, void*, void*);

struct Obj7BEC { void* vtable; };
extern Obj7BEC lbl_27_bss_7BEC;

void fn_27_31EEC4() {
    lbl_27_bss_7BEC.vtable = 0;
    lbl_27_bss_7BEC.vtable = (void*)&lbl_27_data_85D30;
    __register_global_object(&lbl_27_bss_7BEC, (void*)fn_27_31EE84, lbl_27_bss_7BE0);
}
}

__declspec(section ".ctors") extern void* const fn_27_31EEC4_ctor = (void*)fn_27_31EEC4;
