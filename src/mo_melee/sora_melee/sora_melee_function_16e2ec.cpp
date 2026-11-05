#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern GlobalObject lbl_27_bss_4A3C;
extern char lbl_27_data_2F368[];
extern char lbl_27_bss_4A30[];
void fn_27_16E2AC(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_16E2EC() {
    lbl_27_bss_4A3C.vtable = 0;
    lbl_27_bss_4A3C.vtable = &lbl_27_data_2F368;
    __register_global_object((void*)&lbl_27_bss_4A3C, (void*)fn_27_16E2AC, (void*)lbl_27_bss_4A30);
}

__declspec(section ".ctors") extern void* const fn_27_16E2EC_ctor = (void*)fn_27_16E2EC;
