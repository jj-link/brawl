#pragma force_active on
extern "C" void* fn_51_51B8(void* ptr, int size);

struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern signed char lbl_51_bss_48;

struct Obj {
    char flag;
    char pad[3];
    void* data;
};

extern Obj lbl_51_bss_50;
extern DestructorChain lbl_51_bss_18;
extern char lbl_51_data_1908[];
extern char lbl_51_data_18B0[];

extern "C" void* fn_51_50F4() {
    if (lbl_51_bss_48 == 0) {
        lbl_51_bss_50.data = lbl_51_data_1908;
        lbl_51_bss_50.flag = 1;
        lbl_51_bss_50.data = lbl_51_data_18B0;
        __register_global_object(&lbl_51_bss_50, fn_51_51B8, &lbl_51_bss_18);
        lbl_51_bss_48 = 1;
    }
    return &lbl_51_bss_50;
}
