#pragma force_active on
extern "C" {

typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern void *fn_79_3B78(void *p, int n);
extern void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

extern char lbl_79_bss_48;

struct Obj50 {
    char flag;
    char pad[3];
    void *p;
};
extern struct Obj50 lbl_79_bss_50;
extern char lbl_79_data_F58[0x38];
extern char lbl_79_data_F00[0x38];
extern DestructorChain lbl_79_bss_18;

void *fn_79_3AB4(void) {
    if (lbl_79_bss_48 == 0) {
        lbl_79_bss_50.p = &lbl_79_data_F58;
        lbl_79_bss_50.flag = 1;
        lbl_79_bss_50.p = &lbl_79_data_F00;
        __register_global_object(&lbl_79_bss_50, fn_79_3B78, &lbl_79_bss_18);
        lbl_79_bss_48 = 1;
    }
    return &lbl_79_bss_50;
}

}
