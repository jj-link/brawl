#pragma force_active on
extern "C" {

struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
};

void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
void* fn_27_70454(void* p, int n);

extern char lbl_27_bss_1850;
extern void* lbl_27_bss_1854;
extern DestructorChain lbl_27_bss_FF8;

void* fn_27_85D98() {
    if (lbl_27_bss_1850 == 0) {
        lbl_27_bss_1854 = 0;
        __register_global_object(&lbl_27_bss_1854, fn_27_70454, &lbl_27_bss_FF8);
        lbl_27_bss_1850 = 1;
    }
    return &lbl_27_bss_1854;
}

}
