#pragma force_active on

extern "C" {
extern char lbl_27_data_31498[];
extern char lbl_27_bss_4DE0[0xC];
void* fn_27_189E90(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_189ED0(void);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4DEC;

void fn_27_189ED0() {
    lbl_27_bss_4DEC.vtable = 0;
    lbl_27_bss_4DEC.vtable = (void*)&lbl_27_data_31498;
    __register_global_object(&lbl_27_bss_4DEC, (void*)fn_27_189E90, lbl_27_bss_4DE0);
}

__declspec(section ".ctors") extern void* const fn_27_189ED0_ctor;

__declspec(section ".ctors") extern void* const fn_27_189ED0_ctor = (void*)fn_27_189ED0;
