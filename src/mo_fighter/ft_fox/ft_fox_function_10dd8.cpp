#pragma force_active on
struct FoxArticleMediatorStorage { void* primary; void* secondary; };
struct FoxArticleMediatorRegistration { void* next; void* object; void* destructor; };

class FoxArticleMediatorView {
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
extern signed char lbl_97_bss_23C;
extern FoxArticleMediatorStorage lbl_97_bss_240;
extern FoxArticleMediatorRegistration lbl_97_bss_1DC;
extern unsigned char lbl_97_data_28CC[];
extern unsigned char lbl_97_data_28A0[];
extern unsigned char lbl_97_data_2838[];
extern unsigned char lbl_97_data_7948[];
void* fn_97_10B64(void*, short);
void __register_global_object(void*, void*, void*);

void fn_97_10DD8() {
    if (lbl_97_bss_23C == 0) {
        lbl_97_bss_240.primary = lbl_97_data_28CC;
        lbl_97_bss_240.secondary = lbl_97_data_28A0;
        lbl_97_bss_240.primary = lbl_97_data_2838;
        lbl_97_bss_240.secondary = lbl_97_data_2838 + 0x10;
        lbl_97_bss_240.primary = lbl_97_data_7948;
        lbl_97_bss_240.secondary = lbl_97_data_7948 + 0x10;
        __register_global_object(&lbl_97_bss_240,
                                 reinterpret_cast<void*>(fn_97_10B64),
                                 &lbl_97_bss_1DC);
        lbl_97_bss_23C = 1;
    }
    reinterpret_cast<FoxArticleMediatorView*>(&lbl_97_bss_240)->dispatch();
}
}
