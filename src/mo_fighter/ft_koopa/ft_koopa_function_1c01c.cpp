#pragma force_active on
struct KoopaArticleMediatorStorage { void* primary; void* secondary; };
struct KoopaArticleMediatorRegistration { void* next; void* object; void* destructor; };
class KoopaArticleMediatorView {
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
extern signed char lbl_102_bss_5EC;
extern KoopaArticleMediatorStorage lbl_102_bss_5F0;
extern KoopaArticleMediatorRegistration lbl_102_bss_58C;
extern unsigned char lbl_102_data_1958[], lbl_102_data_192C[];
extern unsigned char lbl_102_data_18C4[], lbl_102_data_8264[];
void* fn_102_1BEA0(void*, short);
void __register_global_object(void*, void*, void*);
void fn_102_1C01C(void) {
    if (lbl_102_bss_5EC == 0) {
        lbl_102_bss_5F0.primary = lbl_102_data_1958;
        lbl_102_bss_5F0.secondary = lbl_102_data_192C;
        lbl_102_bss_5F0.primary = lbl_102_data_18C4;
        lbl_102_bss_5F0.secondary = lbl_102_data_18C4 + 0x10;
        lbl_102_bss_5F0.primary = lbl_102_data_8264;
        lbl_102_bss_5F0.secondary = lbl_102_data_8264 + 0x10;
        __register_global_object(&lbl_102_bss_5F0, reinterpret_cast<void*>(fn_102_1BEA0), &lbl_102_bss_58C);
        lbl_102_bss_5EC = 1;
    }
    reinterpret_cast<KoopaArticleMediatorView*>(&lbl_102_bss_5F0)->dispatch();
}
}
