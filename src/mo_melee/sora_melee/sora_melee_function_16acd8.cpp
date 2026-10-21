#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void __register_global_object(void *, void *, DestructorChain *);
extern "C" void fn_27_16AC98(void);
extern "C" unsigned char lbl_27_data_2EF30[];
extern "C" unsigned char lbl_27_data_2F018[];
extern "C" unsigned int lbl_27_bss_4994;
extern "C" unsigned int lbl_27_bss_49C8[4];
extern "C" DestructorChain lbl_27_bss_49D8;

extern "C" void fn_27_16ACD8(void) {
    lbl_27_bss_49D8.next = (DestructorChain *)lbl_27_data_2EF30;
    lbl_27_bss_49D8.destructor = (void *)&lbl_27_bss_4994;
    lbl_27_bss_49D8.next = (DestructorChain *)lbl_27_data_2F018;

    __register_global_object(
        &lbl_27_bss_49D8,
        (void *)fn_27_16AC98,
        (DestructorChain *)lbl_27_bss_49C8
    );
}

__declspec(section ".ctors") extern void* const fn_27_16ACD8_ctor = (void*)fn_27_16ACD8;
