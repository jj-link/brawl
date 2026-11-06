#pragma force_active on
struct PeachArticleMediatorStorage {
    void* primary;
    void* secondary;
};

struct PeachArticleMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class PeachArticleMediatorView {
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
extern signed char lbl_103_bss_264;
extern PeachArticleMediatorStorage lbl_103_bss_268;
extern PeachArticleMediatorRegistration lbl_103_bss_204;
extern unsigned char lbl_103_data_1C64[];
extern unsigned char lbl_103_data_1C38[];
extern unsigned char lbl_103_data_1BD0[];
extern unsigned char lbl_103_data_6EE8[];

void* fn_103_13248(void*, short);
void __register_global_object(void*, void*, void*);

void fn_103_134E4(void) {
    if (lbl_103_bss_264 == 0) {
        lbl_103_bss_268.primary = lbl_103_data_1C64;
        lbl_103_bss_268.secondary = lbl_103_data_1C38;
        lbl_103_bss_268.primary = lbl_103_data_1BD0;
        lbl_103_bss_268.secondary = lbl_103_data_1BD0 + 0x10;
        lbl_103_bss_268.primary = lbl_103_data_6EE8;
        lbl_103_bss_268.secondary = lbl_103_data_6EE8 + 0x10;
        __register_global_object(
            &lbl_103_bss_268,
            reinterpret_cast<void*>(fn_103_13248),
            &lbl_103_bss_204);
        lbl_103_bss_264 = 1;
    }
    reinterpret_cast<PeachArticleMediatorView*>(&lbl_103_bss_268)->dispatch();
}
}
