#pragma force_active on
extern "C" {

struct PikachuArticleMediatorStorage {
    void* primary;
    void* secondary;
};

struct PikachuArticleMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class PikachuArticleMediatorView {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void dispatch();
};

extern signed char lbl_98_bss_36C;
extern PikachuArticleMediatorStorage lbl_98_bss_370;
extern PikachuArticleMediatorRegistration lbl_98_bss_2FC;
extern unsigned char lbl_98_data_2914[], lbl_98_data_28E8[], lbl_98_data_2880[], lbl_98_data_82F8[];

void* fn_98_14D3C(void*, short);
void __register_global_object(void*, void*, void*);

void fn_98_14F80(void) {
    if (lbl_98_bss_36C == 0) {
        lbl_98_bss_370.primary = lbl_98_data_2914;
        lbl_98_bss_370.secondary = lbl_98_data_28E8;
        lbl_98_bss_370.primary = lbl_98_data_2880;
        lbl_98_bss_370.secondary = lbl_98_data_2880 + 0x10;
        lbl_98_bss_370.primary = lbl_98_data_82F8;
        lbl_98_bss_370.secondary = lbl_98_data_82F8 + 0x10;
        __register_global_object(&lbl_98_bss_370, reinterpret_cast<void*>(fn_98_14D3C), &lbl_98_bss_2FC);
        lbl_98_bss_36C = 1;
    }
    reinterpret_cast<PikachuArticleMediatorView*>(&lbl_98_bss_370)->dispatch();
}

}