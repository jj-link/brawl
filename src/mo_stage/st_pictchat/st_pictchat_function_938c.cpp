#pragma force_active on
extern "C" void fn_73_9450(void*, int);
extern "C" void* __register_global_object(void*, void*, void*);

struct Obj {
    char c;
    void* ptr;
};

struct DestructorChain {
    void* next;
    void* destructor;
    void* object;
};

extern "C" char lbl_73_bss_3C;
extern "C" struct Obj lbl_73_bss_40;
extern "C" struct DestructorChain lbl_73_bss_18;
extern "C" char lbl_73_data_1D20[];
extern "C" char lbl_73_data_1CC8[];

extern "C" void* fn_73_938C() {
    if (!lbl_73_bss_3C) {
        lbl_73_bss_40.ptr = (void*)lbl_73_data_1D20;
        lbl_73_bss_40.c = 1;
        lbl_73_bss_40.ptr = (void*)lbl_73_data_1CC8;
        __register_global_object((void*)&lbl_73_bss_40, (void*)&fn_73_9450, (void*)&lbl_73_bss_18);
        lbl_73_bss_3C = 1;
    }
    return (void*)&lbl_73_bss_40;
}
