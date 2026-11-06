#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_30A28[];
extern char lbl_27_bss_4C70[0xC];
extern GlobalObject lbl_27_bss_4C7C;
void* fn_27_18378C(void* ptr, int size);
void __register_global_object(void*, void*, void*);
void fn_27_1837CC(void);
}

void fn_27_1837CC(void) {
    lbl_27_bss_4C7C.vtable = 0;
    lbl_27_bss_4C7C.vtable = (void*)&lbl_27_data_30A28;
    __register_global_object((void*)&lbl_27_bss_4C7C, (void*)fn_27_18378C, lbl_27_bss_4C70);
}

__declspec(section ".ctors") extern void* const fn_27_1837CC_ctor = (void*)fn_27_1837CC;
