#pragma force_active on
struct IkeArticleMediatorStorage {
    void* primary;
    void* secondary;
};

struct IkeArticleMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class IkeArticleMediatorView {
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
extern signed char lbl_119_bss_2D8;
extern IkeArticleMediatorStorage lbl_119_bss_2DC;
extern IkeArticleMediatorRegistration lbl_119_bss_284;
extern unsigned char lbl_119_data_17D8[];
extern unsigned char lbl_119_data_17AC[];
extern unsigned char lbl_119_data_1744[];
extern unsigned char lbl_119_data_65D4[];

void* fn_119_1346C(void*, short);
void __register_global_object(void*, void*, void*);

void fn_119_13708(void*) {
    if (lbl_119_bss_2D8 == 0) {
        lbl_119_bss_2DC.primary = lbl_119_data_17D8;
        lbl_119_bss_2DC.secondary = lbl_119_data_17AC;
        lbl_119_bss_2DC.primary = lbl_119_data_1744;
        lbl_119_bss_2DC.secondary = lbl_119_data_1744 + 0x10;
        lbl_119_bss_2DC.primary = lbl_119_data_65D4;
        lbl_119_bss_2DC.secondary = lbl_119_data_65D4 + 0x10;
        __register_global_object(
            &lbl_119_bss_2DC,
            reinterpret_cast<void*>(fn_119_1346C),
            &lbl_119_bss_284);
        lbl_119_bss_2D8 = 1;
    }
    reinterpret_cast<IkeArticleMediatorView*>(&lbl_119_bss_2DC)->dispatch();
}
}
