#pragma force_active on
extern "C" {

struct SoraArticleMediatorStorage {
    void* primary;
    void* secondary;
};

struct SoraArticleMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class SoraArticleMediatorView {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void dispatch();
};

extern signed char lbl_41_bss_238;
extern SoraArticleMediatorStorage lbl_41_bss_23C;
extern SoraArticleMediatorRegistration lbl_41_bss_1F4;
extern unsigned char lbl_41_data_5CDC[], lbl_41_data_5CB0[];
extern unsigned char lbl_41_data_5C48[], lbl_41_data_5BD0[];

void* fn_41_33CF0(void*, short);
void __register_global_object(void*, void*, void*);

void fn_41_33E4C(void) {
    if (lbl_41_bss_238 == 0) {
        lbl_41_bss_23C.primary = lbl_41_data_5CDC;
        lbl_41_bss_23C.secondary = lbl_41_data_5CB0;
        lbl_41_bss_23C.primary = lbl_41_data_5C48;
        lbl_41_bss_23C.secondary = lbl_41_data_5C48 + 0x10;
        lbl_41_bss_23C.primary = lbl_41_data_5BD0;
        lbl_41_bss_23C.secondary = lbl_41_data_5BD0 + 0x10;
        __register_global_object(&lbl_41_bss_23C, reinterpret_cast<void*>(fn_41_33CF0), &lbl_41_bss_1F4);
        lbl_41_bss_238 = 1;
    }
    reinterpret_cast<SoraArticleMediatorView*>(&lbl_41_bss_23C)->dispatch();
}

}