#pragma force_active on
struct ToonlinkArticleMediatorStorage { void* primary; void* secondary; };
struct ToonlinkArticleMediatorRegistration { void* next; void* object; void* destructor; };
class ToonlinkArticleMediatorView {
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
extern signed char lbl_121_bss_22C;
extern ToonlinkArticleMediatorStorage lbl_121_bss_230;
extern ToonlinkArticleMediatorRegistration lbl_121_bss_1CC;
extern unsigned char lbl_121_data_36B4[], lbl_121_data_3688[];
extern unsigned char lbl_121_data_3620[], lbl_121_data_8D48[];
void* fn_121_146C8(void*, short);
void __register_global_object(void*, void*, void*);

void fn_121_14964(void) {
    if (lbl_121_bss_22C == 0) {
        lbl_121_bss_230.primary = lbl_121_data_36B4;
        lbl_121_bss_230.secondary = lbl_121_data_3688;
        lbl_121_bss_230.primary = lbl_121_data_3620;
        lbl_121_bss_230.secondary = lbl_121_data_3620 + 0x10;
        lbl_121_bss_230.primary = lbl_121_data_8D48;
        lbl_121_bss_230.secondary = lbl_121_data_8D48 + 0x10;
        __register_global_object(&lbl_121_bss_230, reinterpret_cast<void*>(fn_121_146C8), &lbl_121_bss_1CC);
        lbl_121_bss_22C = 1;
    }
    reinterpret_cast<ToonlinkArticleMediatorView*>(&lbl_121_bss_230)->dispatch();
}
}
