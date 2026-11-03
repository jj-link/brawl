#pragma force_active on
struct LinkArticleMediatorStorage { void* primary; void* secondary; };
struct LinkArticleMediatorRegistration { void* next; void* object; void* destructor; };
class LinkArticleMediatorView {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_93_bss_22C;
extern LinkArticleMediatorStorage lbl_93_bss_230;
extern LinkArticleMediatorRegistration lbl_93_bss_1CC;
extern unsigned char lbl_93_data_35BC[], lbl_93_data_3590[];
extern unsigned char lbl_93_data_3528[], lbl_93_data_8C28[];
void* fn_93_1467C(void*, short);
void __register_global_object(void*, void*, void*);
void fn_93_14918(void*) {
    if (lbl_93_bss_22C == 0) {
        lbl_93_bss_230.primary = lbl_93_data_35BC;
        lbl_93_bss_230.secondary = lbl_93_data_3590;
        lbl_93_bss_230.primary = lbl_93_data_3528;
        lbl_93_bss_230.secondary = lbl_93_data_3528 + 0x10;
        lbl_93_bss_230.primary = lbl_93_data_8C28;
        lbl_93_bss_230.secondary = lbl_93_data_8C28 + 0x10;
        __register_global_object(&lbl_93_bss_230, reinterpret_cast<void*>(fn_93_1467C), &lbl_93_bss_1CC);
        lbl_93_bss_22C = 1;
    }
    reinterpret_cast<LinkArticleMediatorView*>(&lbl_93_bss_230)->dispatch();
}
}