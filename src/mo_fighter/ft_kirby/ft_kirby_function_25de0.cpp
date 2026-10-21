#pragma force_active on
struct KirbyMediatorStorage { void* primary; void* secondary; };
struct KirbyMediatorRegistration { void* next; void* object; void* destructor; };

class KirbyMediatorView {
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
extern signed char lbl_96_bss_1124;
extern KirbyMediatorStorage lbl_96_bss_1128;
extern KirbyMediatorRegistration lbl_96_bss_1170;
extern unsigned char lbl_96_data_6264[], lbl_96_data_6238[];
extern unsigned char lbl_96_data_61D0[], lbl_96_data_CBFC[];
void* fn_96_23BD4(void*, short);
void __register_global_object(void*, void*, void*);

void fn_96_25DE0() {
    if (lbl_96_bss_1124 == 0) {
        lbl_96_bss_1128.primary = lbl_96_data_6264;
        lbl_96_bss_1128.secondary = lbl_96_data_6238;
        lbl_96_bss_1128.primary = lbl_96_data_61D0;
        lbl_96_bss_1128.secondary = lbl_96_data_61D0 + 0x10;
        lbl_96_bss_1128.primary = lbl_96_data_CBFC;
        lbl_96_bss_1128.secondary = lbl_96_data_CBFC + 0x10;
        __register_global_object(&lbl_96_bss_1128,
                                 reinterpret_cast<void*>(fn_96_23BD4),
                                 &lbl_96_bss_1170);
        lbl_96_bss_1124 = 1;
    }
    reinterpret_cast<KirbyMediatorView*>(&lbl_96_bss_1128)->dispatch();
}
}
