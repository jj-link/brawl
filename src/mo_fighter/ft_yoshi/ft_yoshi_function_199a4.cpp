#pragma force_active on

struct YoshiArticleMediatorStorage {
    void* primary;
    void* secondary;
};

struct YoshiArticleMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class YoshiArticleMediatorView {
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
extern signed char lbl_95_bss_4CC;
extern YoshiArticleMediatorStorage lbl_95_bss_4D0;
extern YoshiArticleMediatorRegistration lbl_95_bss_508;
extern unsigned char lbl_95_data_3008[], lbl_95_data_3070[];
extern unsigned char lbl_95_data_309C[], lbl_95_data_8C90[];
void* fn_95_174BC(void*, short);
void __register_global_object(void*, void*, void*);

void fn_95_199A4(void) {
    if (lbl_95_bss_4CC == 0) {
        lbl_95_bss_4D0.primary = lbl_95_data_309C;
        lbl_95_bss_4D0.secondary = lbl_95_data_3070;
        lbl_95_bss_4D0.primary = lbl_95_data_3008;
        lbl_95_bss_4D0.secondary = lbl_95_data_3008 + 0x10;
        lbl_95_bss_4D0.primary = lbl_95_data_8C90;
        lbl_95_bss_4D0.secondary = lbl_95_data_8C90 + 0x10;
        __register_global_object(&lbl_95_bss_4D0, reinterpret_cast<void*>(fn_95_174BC), &lbl_95_bss_508);
        lbl_95_bss_4CC = 1;
    }
    reinterpret_cast<YoshiArticleMediatorView*>(&lbl_95_bss_4D0)->dispatch();
}
}