#pragma force_active on
struct CaptainArticleMediatorStorage { void* primary; void* secondary; };
struct CaptainArticleMediatorRegistration { void* next; void* object; void* destructor; };
class CaptainArticleMediatorView {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_100_bss_338;
extern CaptainArticleMediatorStorage lbl_100_bss_33C;
extern CaptainArticleMediatorRegistration lbl_100_bss_2E4;
extern unsigned char lbl_100_data_1B38[], lbl_100_data_1B0C[];
extern unsigned char lbl_100_data_1AA4[], lbl_100_data_7038[];
void* fn_100_132E4(void*, short);
void __register_global_object(void*, void*, void*);
void fn_100_13580(void*) {
    if (lbl_100_bss_338 == 0) {
        lbl_100_bss_33C.primary = lbl_100_data_1B38;
        lbl_100_bss_33C.secondary = lbl_100_data_1B0C;
        lbl_100_bss_33C.primary = lbl_100_data_1AA4;
        lbl_100_bss_33C.secondary = lbl_100_data_1AA4 + 0x10;
        lbl_100_bss_33C.primary = lbl_100_data_7038;
        lbl_100_bss_33C.secondary = lbl_100_data_7038 + 0x10;
        __register_global_object(&lbl_100_bss_33C, reinterpret_cast<void*>(fn_100_132E4), &lbl_100_bss_2E4);
        lbl_100_bss_338 = 1;
    }
    reinterpret_cast<CaptainArticleMediatorView*>(&lbl_100_bss_33C)->dispatch();
}
}