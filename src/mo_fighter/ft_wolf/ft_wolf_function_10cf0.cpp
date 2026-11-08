#pragma force_active on
struct WolfArticleMediatorStorage { void* primary; void* secondary; };
struct WolfArticleMediatorRegistration { void* next; void* object; void* destructor; };
class WolfArticleMediatorView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_125_bss_23C;
extern WolfArticleMediatorStorage lbl_125_bss_240;
extern WolfArticleMediatorRegistration lbl_125_bss_1DC;
extern unsigned char lbl_125_data_2908[], lbl_125_data_28DC[];
extern unsigned char lbl_125_data_2874[], lbl_125_data_798C[];
void* fn_125_10A7C(void*, short);
void __register_global_object(void*, void*, void*);
void fn_125_10CF0(void*) {
    if (lbl_125_bss_23C == 0) {
        lbl_125_bss_240.primary = lbl_125_data_2908;
        lbl_125_bss_240.secondary = lbl_125_data_28DC;
        lbl_125_bss_240.primary = lbl_125_data_2874;
        lbl_125_bss_240.secondary = lbl_125_data_2874 + 0x10;
        lbl_125_bss_240.primary = lbl_125_data_798C;
        lbl_125_bss_240.secondary = lbl_125_data_798C + 0x10;
        __register_global_object(&lbl_125_bss_240, reinterpret_cast<void*>(fn_125_10A7C), &lbl_125_bss_1DC);
        lbl_125_bss_23C = 1;
    }
    reinterpret_cast<WolfArticleMediatorView*>(&lbl_125_bss_240)->dispatch();
}
}